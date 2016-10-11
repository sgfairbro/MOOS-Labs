/************************************************************/
/*    NAME: Shane Fairbrother                                              */
/*    ORGN: MIT                                             */
/*    FILE: CommunicationAngle.h                                          */
/*    DATE:                                                 */
/************************************************************/
#ifndef CommunicationAngle_HEADER
#define CommunicationAngle_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "MBUtils.h"
#include "AcousticCalculator.h"
#include "AcousticStruct.cpp"
#include <iterator>
#include <memory>

using namespace std; 

class CommunicationAngle : public CMOOSApp
{
 public:
   CommunicationAngle();
   ~CommunicationAngle();

 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
   unsigned int m_iterations;
   double       m_timewarp;
   double       m_time_interval;
   double       m_water_depth; 
   double       m_sound_speed_gradient; 
   double       m_surface_sound_speed; 
   AcousticStruct* m_currentParameters; 
   AcousticCalculator* m_calculator; 
   
};

#endif 