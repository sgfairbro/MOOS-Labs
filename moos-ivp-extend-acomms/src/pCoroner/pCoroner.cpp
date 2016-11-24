// t. schneider tes@mit.edu 03.04.09
// ocean engineering graduate student - mit / whoi joint program
// massachusetts institute of technology (mit)
// laboratory for autonomous marine sensing systems (lamss)
// 
// this is pCoroner.cpp 
//
// see the readme file within this directory for information
// pertaining to usage and purpose of this script.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this software.  If not, see <http://www.gnu.org/licenses/>.

#include "pCoroner.h"

#if GOBY_VERSION_MAJOR >= 2
#include "goby/util/as.h"
#else
#include "goby/util/string.h"
#endif

using namespace std;
using goby::util::as;
using boost::trim_copy;

// Construction / Destruction
CpCoroner::CpCoroner(): start_time_(MOOSTime())
{
}
CpCoroner::~CpCoroner()
{
}

// OnNewMail: called when new mail (previously registered for)
// has arrived.
bool CpCoroner::OnNewMail(MOOSMSG_LIST &NewMail)
{
    // read all the new mail
for(MOOSMSG_LIST::iterator p = NewMail.begin(); p != NewMail.end(); p++)
    {
        CMOOSMsg &msg = *p;
        
        string key   = msg.GetKey(); 	
//	bool is_dbl  = msg.IsDouble();
//	bool is_str  = msg.IsString();
//        double dval  = msg.GetDouble();
	string sval  = msg.GetString();

	// uncomment as needed
        // double msg_time = msg.GetTime();
	// string msg_src  = msg.GetSource();
	// string msg_community = msg.GetCommunity();
	

	if(MOOSStrCmp(key, "DB_CLIENTS") && (MOOSTime() > start_time_ + WAIT)) // case insensitive
        {
            vector<string>running;
            boost::split(running, sval, boost::is_any_of(","));
            vector<string>dead = check_dead(running);

            std::cout << "summary @ " << MOOSTime() << ":" << std::endl;
            
            if(dead.size() > 0)
            {
                string dead_list = "dead:";
                for(vector<string>::size_type i = 0, n = dead.size(); i < n; ++i)
                {
                    if(i)
                        dead_list += ",";
                    
                    dead_list += dead[i];
                }
                std::cout << "(Warning): " << dead_list << std::endl;
                m_Comms.Notify(out_var_, dead_list);
                
            }
            else
            {
                string good = "all " + as<std::string>(processes_.size()) + " processes alive!";
                std::cout << good << std::endl;
                m_Comms.Notify(out_var_, good);
            }
            

        }
        else if(MOOSStrCmp(key, "ANTLER_START_LIST")) // case insensitive
        {
            vector<string> vs;
            boost::split(vs, sval, boost::is_any_of(","));
            for(vector<string>::iterator it = vs.begin(), n = vs.end(); it != n; ++it)
                processes_.insert(*it);

            publish_start_list(sval);
            
        }

        //
        // Only works with the pAntler modifications made by NURC,
        // which publishes the names of all launched processes in the ANTLER_LAUNCHED_PROCESSES variable.
        //
        else if(MOOSStrCmp(key, "ANTLER_LAUNCHED_PROCESSES")) // case insensitive
        {
            vector<string> vs;
            boost::split(vs, sval, boost::is_any_of(","));
            for(vector<string>::iterator it = vs.begin(), n = vs.end(); it != n; ++it) {
                if(*it != "MOOSDB" && *it != "uMS") {
                    processes_.insert(*it);
                }
            }
            publish_start_list(sval);
            
        }
    }  
    return true;
}

// OnConnectToServer: called when connection to the MOOSDB is
// complete
bool CpCoroner::OnConnectToServer()
{
    if (!ReadConfiguration())
	return false;
 
    RegisterVariables();   
    return true;
}

// Iterate: called AppTick times per second
bool CpCoroner::Iterate()
{ 
    return true;
}

// OnStartUp: called when program is run
bool CpCoroner::OnStartUp()
{
    return true;
}

// RegisterVariables: register for variables we want to get mail for
void CpCoroner::RegisterVariables()
{
    m_Comms.Register("DB_CLIENTS", 3); 
    m_Comms.Register("ANTLER_START_LIST", 0);    

    //
    // Only works with the pAntler modifications made by NURC,
    // which publishes the names of all launched processes in the ANTLER_LAUNCHED_PROCESSES variable.
    //
    m_Comms.Register("ANTLER_LAUNCHED_PROCESSES", 0);    
}

// ReadConfiguration: reads in configuration values from the .moos file
// parameter keys are case insensitive
bool CpCoroner::ReadConfiguration()
{
    out_var_ = boost::to_upper_copy(GetAppName()) + (string)"_SUMMARY";
    m_MissionReader.GetConfigurationParam("summary_var", out_var_);
    
     list<string> params;
     if(m_MissionReader.GetConfiguration("ANTLER", params))
     {
         params.reverse();
         for(list<string>::iterator it = params.begin(); it !=params.end(); ++it)
         {
             string value = trim_copy(*it);
             string key = trim_copy(MOOSChomp(value, "="));

             bool bInhibitMOOSParams = false;
             MOOSValFromString(bInhibitMOOSParams, value, "InhibitMOOSParams", true);
             
             if(boost::iequals(key, "Run"))
             {
                 string::size_type pos = value.find("~");
                 string process_name;
                 if(pos == string::npos)
                     process_name = MOOSChomp(value, "@");
                 else
                 {
                     MOOSChomp(value, "~");
                     process_name = value;
                 }
                 
                 
                 if(process_name != "MOOSDB" && process_name != "uMS" && !bInhibitMOOSParams)
                     processes_.insert(process_name);
             }
         }
     }

     publish_start_list("");
     
    
    return true;
}

vector<string> CpCoroner::check_dead(const vector<string> & running)
{
    vector<string> dead;
    
    for(set<string>::iterator it = processes_.begin(), n = processes_.end(); it != n; ++it)
    {
        bool found = false;
        for (vector<string>::const_iterator it2 = running.begin(), n2 = running.end(); it2 != n2; ++it2)
        {
            // some processes append things to the end of their name...
            if(it->find("pMOOSBridge") != std::string::npos || 
               it->find("uXMS") != std::string::npos)
            {
                if(!it->compare(0, it->size(), (*it2), 0, it->size()))
                    found = true;    
            }
            else
            {
                if((*it) == (*it2))
                    found = true;
            }
        }

        if(!found)
            dead.push_back(*it);
    }
    return dead;

}


void CpCoroner::publish_start_list(std::string old_list)
{
    string list;
    for(set<string>::iterator it = processes_.begin(), n = processes_.end(); it != n; ++it)
        list += *it + ",";
    
    if(list != old_list)    
        m_Comms.Notify("ANTLER_START_LIST", list);
}
