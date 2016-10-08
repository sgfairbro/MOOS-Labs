/* 
 * File:   PrimeMap.h
 * Author: sgfairbro
 *
 * Created on September 8, 2016
 */


#ifndef PRIMEMAP_H
#define	PRIMEMAP_H

#include <cstdlib>
#include <vector>
#include "PrimeEntry.h"

using namespace std; 

class PrimeMap{
    
public:
    PrimeMap();
    PrimeMap(const PrimeMap& orig);
    virtual ~PrimeMap();
    void insert(unsigned long int, PrimeEntry*); 
    PrimeEntry* popPrime(unsigned long int); 
    int findKey(unsigned long int); 
    bool isEmpty(); 
    void findPrimes(unsigned long int);
    
private:
    vector<PrimeEntry*>* m_primes; 
    vector<unsigned long int>* m_keys; 
    
};

#endif	/* PRIMEMAP_H */

