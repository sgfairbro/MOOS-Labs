/* 
 * File:   PrimeQueue.cpp
 * Author: sgfairbro
 * 
 * Created on September 8, 2016
 */
 
 /*
  * This class is a simple queue data structured used for storing the received index of
  * each prime number received in the PrimeFactor application. Received indices are 
  * saved to the queue when a number is factored. The PrimeFactor application pops
  * indices from the queue to find out which PrimeEntry objects have finished calculating
  * the prime factorization of their numbers. 
  * 
  * */

#include "PrimeQueue.h"


PrimeQueue::PrimeQueue() {
    m_queue = new queue<unsigned long int>; 
}

PrimeQueue::PrimeQueue(const PrimeQueue& orig) {
    
}

PrimeQueue::~PrimeQueue() {
    queue<unsigned long int>* empty; 
    swap(m_queue, empty); 
    delete m_queue; 
}

//Insert an element into the queue
void PrimeQueue::push(unsigned long int elem){
    m_queue->push(elem); 
}

unsigned long int PrimeQueue::pop(){
    
    unsigned long int frontval;
    
    if (m_queue->empty()){
        frontval =  -1;
    }
    else{
        frontval = m_queue->front(); 
        m_queue->pop(); 
    }
    
    return frontval; 
    
}

int PrimeQueue::size(){
    
        return m_queue->size();
}

bool PrimeQueue::isEmpty(){
    
    return m_queue->empty(); 
    
}