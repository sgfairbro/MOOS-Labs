/************************************************************/
/*    NAME: Shane Fairbrother                                              */
/*    ORGN: MIT                                             */
/*    FILE: CommunicationAngle.cpp                                        */
/*    DATE:                                                 */
/************************************************************/


#include "CommunicationAngle.h"

//---------------------------------------------------------
// Constructor

CommunicationAngle::CommunicationAngle()
{

  m_currentParameters = new AcousticStruct();
  m_calculator = new AcousticCalculator(*m_currentParameters);
  
  //Set defaults
  m_time_interval = 3; // seconds
  m_water_depth = 6000; // meters
  m_surface_sound_speed = 1480; // m/s
  m_sound_speed_gradient = 0.016; // (m/s)/m

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

  }
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool CommunicationAngle::OnConnectToServer()
{
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
// This function will solve for an acoustic path between the two vehicles
// every m_time_interval seconds. If Apptick has been set to a longer time
// than m_time_interval, then the time between calculations will be governed
// by Apptick instead. 
bool CommunicationAngle::Iterate()
{
  static double previousTime = MOOSTime(); 

  if (previousTime - MOOSTime() > m_time_interval){
    
    string result; 

    if (m_calculator->solvePath()){
      result = m_calculator->pathString();
      m_Comms.Notify("ACOUSTIC_PATH", result);
    }
    else{
      result = m_calculator->connectivityLocString();
      m_Comms.Notify("CONNECTIVITY_LOCATION", result);
    }
  }
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
        m_surface_sound_speed = strtod(value.c_str(), NULL); 
      }
      //Sound speed gradient with depth, in (m/s)/m
      else if(param == "sound_speed_gradient") {
        m_sound_speed_gradient = strtod(value.c_str(), NULL);
      }
      //Water depth in meters
      else if(param == "water_depth") {
        m_water_depth = strtod(value.c_str(), NULL); 
      }
      //Time interval in seconds between estimates
      else if(param == "time_interval") {
        m_time_interval = strtod(value.c_str(), NULL); 
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
