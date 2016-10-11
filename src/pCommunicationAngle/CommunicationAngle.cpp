/************************************************************/
/*    NAME: Shane Fairbrother                                              */
/*    ORGN: MIT                                             */
/*    FILE: CommunicationAngle.cpp                                        */
/*    DATE:                                                 */
/************************************************************/


#include "CommunicationAngle.h"

using namespace std;

//---------------------------------------------------------
// Constructor

CommunicationAngle::CommunicationAngle()
{

  m_currentParameters = new AcousticStruct();
  m_calculator = new AcousticCalculator(*m_currentParameters);
  //calculator = make_unique<AcousticCalculator>();
}

//---------------------------------------------------------
// Destructor

CommunicationAngle::~CommunicationAngle()
{
  delete m_currentParameters; 
  delete m_calculator; 
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool CommunicationAngle::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key = msg.GetKey(); 

    if (key == "VEHICLE_NAME"){
      m_currentParameters->vehicleName = msg.GetDouble();
    }
    else if (key == "COLLABORATOR_NAME"){
      m_currentParameters->collaboratorName = msg.GetDouble(); 
    }
    else if (key == "NAV_X"){
      m_currentParameters->navX = msg.GetDouble(); 
    }
    else if (key == "NAV_Y"){
      m_currentParameters->navY = msg.GetDouble(); 
    }
    else if (key == "NAV_DEPTH"){
      m_currentParameters->navDepth = msg.GetDouble(); 
    }
    else if (key == "NAV_HEADING"){
      m_currentParameters->navHeading = msg.GetDouble(); 
    }
    else if (key == "NAV_SPEED"){
      m_currentParameters->navSpeed = msg.GetDouble(); 
    }
    else if (key == "collaborator_NAV_X"){
      m_currentParameters->navXCollaborator = msg.GetDouble(); 
    }
    else if (key == "collaborator_NAV_Y"){
      m_currentParameters->navYCollaborator= msg.GetDouble(); 
    }
    else if (key == "collaborator_NAV_DEPTH"){
      m_currentParameters->navDepthCollaborator = msg.GetDouble(); 
    }
    else if (key == "collaborator_NAV_HEADING"){
      m_currentParameters->navHeadingCollaborator = msg.GetDouble(); 
    }
    else if (key == "collaborator_NAV_SPEED"){
      m_currentParameters->navSpeedCollaborator = msg.GetDouble();
    }

#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool CommunicationAngle::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);
	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool CommunicationAngle::Iterate()
{
  static double previousTime = MOOSTime(); 
  m_iterations++;
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool CommunicationAngle::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      //Sound speed in m/s at the sea surface
      if(param == "surface_sound_speed") {
        m_surface_sound_speed = strtod(value, NULL); 
      }
      //Sound speed gradient with depth, in (m/s)/m
      else if(param == "sound_speed_gradient") {
        m_sound_speed_gradient = strtod(value, NULL);
      }
      //Water depth in meters
      else if(param == "water_depth") {
        m_water_depth = strtod(value, NULL); 
      }
      //Time interval in seconds between estimates
      else if(param == "time_interval") {
        m_time_interval = strtod(value, NULL); 
      }
    }
  }

  m_timewarp = GetMOOSTimeWarp();

  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void CommunicationAngle::RegisterVariables()
{
  Register("VEHICLE_NAME", 0);
  Register("COLLABORATOR_NAME", 0);
  Register("NAV_X", 0);
  Register("NAV_Y", 0);
  Register("NAV_DEPTH", 0);
  Register("NAV_HEADING", 0);
  Register("NAV_SPEED", 0);
  Register("collaborator_NAV_X", 0);
  Register("collaborator_NAV_Y", 0);
  Register("collaborator_NAV_DEPTH", 0);
  Register("collaborator_NAV_HEADING", 0);
  Register("collaborator_NAV_SPEED", 0);
}

