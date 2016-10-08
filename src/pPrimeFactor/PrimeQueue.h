/* 
 * File:   PrimeQueue.h
 * Author: sgfairbro
 *
 * Created on September 8, 2016
 */


#ifndef PRIMEQUEUE_H
#define	PRIMEQUEUE_H

/*PrimeEntry specs
 * original number
 * index indicating the order in which it was received
 * index indicating order in which it was calculated
 * 
 * the time it took to solve the factorization. This is in normal
 * clock time, not CPU time. Use the MOOSTime() function to get the
 * 
 * time when it was received and the time it was finished 
 * The list of prime factors
 * 
 * A unique id specifying you, e.g. your username
 * 
 * Result should look like:
 * PRIME_RESULT = "orig=30030,received=34,calculated=33,solve_time=2.03,
 primes=2:3:5:7:11:13,username=jane" 
 
 
 */

#include <cstdlib>
#include <queue>

using namespace std; 

class PrimeQueue{
    
public:
    PrimeQueue();
    PrimeQueue(const PrimeQueue& orig);
    virtual ~PrimeQueue();
    void push(unsigned long int);
    unsigned long int pop(); 
    int size(); 
    bool isEmpty(); 
    
private:
    queue<unsigned long int> *m_queue; 
   
};

#endif	/* PRIMEQUEUE_H */

