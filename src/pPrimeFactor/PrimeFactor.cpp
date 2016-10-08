/************************************************************/
/*    NAME: Shane Fairbrother                                                                           */
/*    ORGN: MIT                                                                                                           */
/*    FILE: PrimeFactor.cpp                                                                                   */
/*    DATE: 09/26/2016                                                                                            */
/************************************************************/

/*This is the main class in the pPrimeFactor application that  is derived
 * from CMOOSApp.  It is used to calculate the prime factorization of 
 * 64-bit integers. Incoming values are accepted as strings in the variable
 * NUM_VALUE. A detailed factorization result is posted to PRIME_RESULT
 * each time a number is factored. 
 * */

#include "PrimeFactor.h"

using namespace std;

//---------------------------------------------------------
// Constructor

PrimeFactor::PrimeFactor()
{
  m_iterations = 0;
  m_timewarp   = 1;
  m_received_index = 0;
  m_calculated_index = 0;
  m_username = "jane"; 
  m_steps_per_calc = 1000;
  m_calc_primes = new PrimeQueue(); 
  m_prime_entries = new PrimeMap(); 
}

//---------------------------------------------------------
// Destructor

PrimeFactor::~PrimeFactor()
{
    delete m_calc_primes; 
    m_calc_primes = NULL;
    
    delete m_prime_entries; 
    m_prime_entries = NULL; 
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactor::OnNewMail(MOOSMSG_LIST &NewMail)
{
    
  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key = msg.GetKey();
 
   if(key == "NUM_VALUE"){
       
        string num = msg.GetString();
        unsigned long int x= strtoul(num.c_str(), NULL, 0);
        
        //Create the new PrimeEntry with the number to be factored, x
        PrimeEntry* newPrime = new PrimeEntry(x); 
        newPrime->setInitialTime(msg.GetTime()); 
        newPrime->setReceivedIndex(m_received_index); 
        newPrime->setUserName(m_username); 
        
        //Give the PrimeEntry the PrimeQueue pointer so it can tell us when it's done. 
        newPrime->m_calculated_primes = m_calc_primes; 
        
        //Insert the PrimeEntry into our map data structure so we can access it later
        m_prime_entries->insert(m_received_index++, newPrime);  
    }

   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PrimeFactor::OnConnectToServer()
{	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool PrimeFactor::Iterate()
{
        //Make sure we've actually received a NUM_VALUE
        if (m_received_index > 0){
            
            //Calculate the prime factorization of any numbers in the map container
            if (!m_prime_entries->isEmpty()){
                m_prime_entries->findPrimes(m_steps_per_calc); 
            }
            
            int prime_queue_size = m_calc_primes->size(); 
            
             for (int i = 0; i < prime_queue_size; i++){
                 //Pop out the recieved index from the queue and use it as a key to access the PrimeEntry that has been solved
                 unsigned long int  key = m_calc_primes->pop(); 
                 PrimeEntry* solvedPrime = m_prime_entries->popPrime(key);
                 
                 //Set the index in which the PrimeEntry was solved
                 solvedPrime->setCalculatedIndex(m_calculated_index++); 
                 
                 //Post the results to the MOOSDB
                 if (solvedPrime != NULL){
                        string result = solvedPrime->displayResults();
                        m_Comms.Notify("PRIME_RESULT", result); 
                 }
                
            }
        }
        
  m_iterations++;
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool PrimeFactor::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      if(param == "USERNAME") {
        m_username = value; 
      }
      else if(param == "STEPS") {
          m_steps_per_calc = strtoul(value.c_str(), NULL, 0);
      }
    }
  }
  
  m_timewarp = GetMOOSTimeWarp();

  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void PrimeFactor::RegisterVariables()
{
  Register("NUM_VALUE", 0);
}