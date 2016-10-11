/* 
 * File:   PrimeMap.cpp
 * Author: sgfairbro
 * 
 * Created on September 8, 2016
 */

#include "PrimeMap.h"

/* This class is a map data structure used to associate the received index of a PrimeEntry
 * to the PrimeEntry it corresponds to. PrimeEntry pointers can be accessed in this data 
 * structure by providing a valid received index. The PrimeFactor application uses received
 * indices taken from the PrimeQueue data structure to access completed PrimeEntry
 * classes stored in this class.
 * 
 * */


PrimeMap::PrimeMap() {
    m_primes = new vector<PrimeEntry*>; 
    m_keys = new  vector<unsigned long int>; 
}

PrimeMap::PrimeMap(const PrimeMap& orig) {
    
}

PrimeMap::~PrimeMap() {
    m_keys->clear(); 
    delete m_keys;
    m_keys = NULL; 
    
    for (vector<PrimeEntry*>::iterator it = m_primes->begin(); it != m_primes->end(); ++it){
        delete (*it); 
    }
    m_primes->clear(); 
    delete m_primes; 
    m_primes = NULL;

}

void PrimeMap::insert(unsigned long int key, PrimeEntry* prime){
    
    m_keys->push_back(key);
    m_primes->push_back(prime); 
    
}

//Calculate the prime numbers of all the PrimeEntry objects in m_primes
void PrimeMap::findPrimes(unsigned long int steps){
    
    if (this->isEmpty()){
        return; 
    }
    
    for (vector<PrimeEntry*>::iterator it=m_primes->begin(); it != m_primes->end(); ++it){
        (*it)->findPrimes(steps); 
    }    
    
}

//Searches through  m_keys and returns the index of the specified key. Returns -1 i the key isn't found
int PrimeMap::findKey(unsigned long int key){
    
    int iter = 0; 
    int index = -1; 
    for (vector<unsigned long int>::iterator it=m_keys->begin(); it != m_keys->end(); ++it){
        if (*it == key){
            index = iter; 
            break; 
        }
        iter++; 
    }
    
    return index; 
    
}

PrimeEntry* PrimeMap::popPrime(unsigned long int key){
    
    int index = findKey(key); 
    if (index ==-1)
        return NULL; 

    //Get the PrimeEntry pointer
    PrimeEntry* thePrime = m_primes->at(index); 
    
    //Erase the prime entry and its key from the vector
    m_primes->erase(m_primes->begin() + index); 
    m_keys->erase(m_keys->begin() + index); 
    
    return thePrime; 
        
}

bool PrimeMap::isEmpty(){
    
    return  m_primes->empty();
    
}