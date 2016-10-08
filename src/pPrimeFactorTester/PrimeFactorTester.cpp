/************************************************************/
/*    NAME: Shane Fairbrother                                              */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactorTester.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "PrimeFactorTester.h"

//---------------------------------------------------------
// Constructor

PrimeFactorTester::PrimeFactorTester()
{
  m_iterations = 0;
  m_timewarp   = 1;
}

//---------------------------------------------------------
// Destructor

PrimeFactorTester::~PrimeFactorTester()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactorTester::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key = msg.GetKey(); 
    
    if (key == "PRIME_RESULT"){
        string result = msg.GetString();
        
        //Pull out the value of the original number from the result string
        string orig = tokStringParse(result, "orig", ',', '='); 
        unsigned long int originalNumber = strtoul(orig.c_str(), NULL, 0);
        
        //Store the prime factorization in a colon-separated string (e.g. "2, 5, 7")
        string primes_str = tokStringParse(result, "primes", ',', '=');
        
        //Parse that string into a string vector
        vector<string> primes_str_vector = parseString(primes_str, ':');
        
        //Store the primes in a numerical vector
        vector<unsigned long int> primes(primes_str_vector.size()); 
        
        int iter = 0; 
        for (vector<string>::iterator it= primes_str_vector.begin(); it != primes_str_vector.end(); ++it){
            primes.at(iter) =  strtoul((*it).c_str(), NULL, 0);
            iter++;
        }
        
        //Check if the prime factorization multiplies to the original number
        bool valid = validatePrimeFactors(originalNumber, primes);
        
        //Post the result with whether or not it was valid
        result = result + ",valid=" + boolToString(valid); 
        m_Comms.Notify("PRIME_RESULT_VALID", result); 
        
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

bool PrimeFactorTester::OnConnectToServer()
{	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool PrimeFactorTester::Iterate()
{
  m_iterations++;
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool PrimeFactorTester::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
    }
  }
  
  m_timewarp = GetMOOSTimeWarp();

  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void PrimeFactorTester::RegisterVariables()
{
  Register("PRIME_RESULT", 0);
}

//This function checks if the numbers in primes multiply to bigNumber. Returns true if the do, false if they don't
bool PrimeFactorTester::validatePrimeFactors(unsigned long int bigNumber, vector<unsigned long int> primes){
    
    unsigned long int result = 1; 
    
    for (vector<unsigned long int>::iterator it = primes.begin(); it != primes.end(); ++it){
        result = result * (*it); 
    }
    
    if (result == bigNumber)
        return true; 
    else
        return false;
    
}