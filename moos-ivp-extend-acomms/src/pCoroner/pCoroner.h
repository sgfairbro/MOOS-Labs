// t. schneider tes@mit.edu 03.04.09
// ocean engineering graduate student - mit / whoi joint program
// massachusetts institute of technology (mit)
// laboratory for autonomous marine sensing systems (lamss)
// 
// this is pCoroner.h 
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

#ifndef pCoronerH
#define pCoronerH

#include "MOOS/libMOOS/MOOSLib.h"
#include <boost/algorithm/string.hpp>

#include "goby/version.h"

// wait before checking if all alive
const double WAIT = 5;

class CpCoroner : public CMOOSApp  
{
  public:
    CpCoroner();
    virtual ~CpCoroner();

  private:
    bool OnNewMail(MOOSMSG_LIST &NewMail);
    bool Iterate();
    bool OnConnectToServer();
    bool OnStartUp();

    void RegisterVariables();
    bool ReadConfiguration();

    std::vector<std::string> check_dead(const std::vector<std::string> & running);
    void publish_start_list(std::string sval);

    std::string out_var_;

    double start_time_;
    
    std::set<std::string>processes_;
};

#endif 
