/************************************************************/
/*    NAME: Shane Fairbrother                                                                           */
/*    ORGN: MIT                                                                                                           */
/*    FILE: PrimeFactor.h                                                                                        */
/*    DATE: 09/26/2016                                                                                            */
/************************************************************/

#ifndef PrimeFactor_HEADER
#define PrimeFactor_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "PrimeEntry.h"
#include "PrimeQueue.h"
#include "PrimeMap.h"
#include "MBUtils.h"
#include <iterator>
#include <map>
#include <cstdlib>

using namespace std;

class PrimeFactor : public CMOOSApp
{
 public:
   PrimeFactor();
   ~PrimeFactor();

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
   PrimeMap* m_prime_entries; 
   PrimeQueue *m_calc_primes;
   unsigned long int m_received_index; 
   unsigned long int m_calculated_index; 
   unsigned long int m_steps_per_calc; 
   string m_username; 
   
};

#endif 
