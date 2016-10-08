/* 
 * File:   PrimeEntry.cpp
 * Author: sgfairbro
 * 
 * Created on September 8, 2016, 6:42 PM
 */

#include "PrimeEntry.h"

/*The PrimeEntry class is used to calculate the prime factorization of a number.
 * Numbers are received as 64-bit integers with a maximum value of 
 * 18,446,744,073,709,551,615. Results can be stored in a string and displayed. 
 */

PrimeEntry::PrimeEntry(unsigned long int entry) {
    //initialize variables
    m_original_number = entry; 
    m_current_number = entry; 
    m_primes = new vector<unsigned long int>; 
    m_index = 2;
    m_done = false; 
    
    //defaults - still need to be set later
    m_calculated_index = 0;
    m_received_index = 0; 
    m_solve_time = 0;
    m_username = "sgfairbro"; 
}

PrimeEntry::PrimeEntry(const PrimeEntry& orig) {
    delete m_primes;
    m_primes = NULL; 
}

PrimeEntry::~PrimeEntry() {
    delete m_primes;
    m_primes = NULL;
}

/*This function calculates the prime factorization of m_original_number
* by iterating between 2 and the square root of m_original_number. If the
* number of steps taken in the while loop exceeds the maximum set by
* max steps, the number is saved in m_current_number and the factorization
* can be resumed later. 
 */
void PrimeEntry::findPrimes(unsigned long int max_steps){
    double primesqrt = sqrt(m_original_number);
    unsigned long int steps = 0; 
    
    while (m_index <= primesqrt){
        if (m_current_number % m_index == 0){
            divide(m_index); 
        }
        else{
            m_index++; 
        }
        
        if (++steps >= max_steps){
            return; 
        }
        
    }
    
    m_done = true;
    this->calculateTime(); 
    if (m_current_number > 1)
        m_primes->push_back(m_current_number);
    
    //Push back the received index to the PrimeQueue so PrimeFactor
    //knows this entry has completed factoring. 
    m_calculated_primes->push(m_received_index); 
}

void PrimeEntry::divide(unsigned long int& divisor){
    if (m_current_number % divisor == 0){
        m_current_number /= divisor; 
        m_primes->push_back(divisor);
        divide(divisor); 
    }
    else{
        return;
    }
}

//Display the results of the factorization
//example: orig=30030,received=34,calculated=33,solve_time=2.03,
 //primes=2:3:5:7:11:13,username=jane"
string PrimeEntry::displayResults(){
    stringstream ss; 
    ss << "orig=" << m_original_number;
    ss <<  ",received=" << m_received_index;
    ss << ",calculated=" << m_calculated_index;
    ss << ",solve_time="<< m_solve_time; 
    ss << ",primes=";
    vector<unsigned long int>::iterator it;
    for (it = m_primes->begin(); it != m_primes->end();){
        ss << *it ;
        if (++it != m_primes->end()){
            ss << ":"; 
        }
    }
    ss <<",username=" << m_username;
    
    return ss.str(); 
    
}

//Find the time it took to calculate the prime factorization
void PrimeEntry::calculateTime(){
    
    m_solve_time = MOOSTime() - m_initial_time;
    
}

//This can be used to display the prime numbers found in the factorization
void PrimeEntry::displayPrimes(){
    vector<unsigned long int>::iterator it; 
    for (it = m_primes->begin(); it != m_primes->end(); ++it){
        unsigned long int val = *it; 
        cout << val << endl; 
    }
}