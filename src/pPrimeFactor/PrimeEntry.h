/* 
 * File:   PrimeEntry.h
 * Author: sgfairbro
 *
 * Created on September 8, 2016, 6:42 PM
 */

#ifndef PRIMEENTRY_H
#define	PRIMEENTRY_H

#include "MOOS/libMOOS/MOOSLib.h"
#include "PrimeQueue.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std; 

class PrimeEntry {
public:
    PrimeEntry(unsigned long int);
    PrimeEntry(const PrimeEntry& orig);
    virtual ~PrimeEntry();
    void findPrimes(unsigned long int);
    void displayPrimes(); 
    void setReceivedIndex(unsigned long int v) {m_received_index = v;};
    void setCalculatedIndex(unsigned long int v) {m_calculated_index = v;}; 
    void setInitialTime(double v){m_initial_time =v;};
    void setUserName(string v){m_username=v;};
    void calculateTime();
    bool isDone() {return m_done;}; 
    string displayResults(); 
    
    //This is a pointer to the queue used for storing m_received_index
    //when a PrimeEntry instance finishes factoring. 
    PrimeQueue*  m_calculated_primes; 
    
private:
    void divide(unsigned long int&); 
    unsigned long int m_index; 
    unsigned long int m_original_number; 
    unsigned long int m_current_number; 
    unsigned int m_received_index;//the index at which it was received
    unsigned int m_calculated_index; //the index at which it was solved
    vector<unsigned long int>* m_primes; //Prime factorization numbers
    bool m_done; 
    string m_username; 
    double m_initial_time;
    double m_solve_time; 
    unsigned long int m_steps; //Steps to use in for loop for a calculation
   
};

#endif	/* PRIMEENTRY_H */

