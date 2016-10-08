/************************************************************/
/*    NAME: Shane Fairbrother                                              */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactorTester.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef PrimeFactorTester_HEADER
#define PrimeFactorTester_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include <vector>

using namespace std; 

class PrimeFactorTester : public CMOOSApp
{
 public:
   PrimeFactorTester();
   ~PrimeFactorTester();

 protected:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   void RegisterVariables();
   bool validatePrimeFactors(unsigned long int, vector<unsigned long int>); 

 private: // Configuration variables

 private: // State variables
   unsigned int m_iterations;
   double       m_timewarp;
};

#endif 