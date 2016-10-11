/* 
 * File:   ACOUSTICCALCULATOR.h
 * Author: sgfairbro
 *
 * Created on October 2nd, 2016
 */
#ifndef ACOUSTICCALCULATORH
#define	ACOUSTICCALCULATOR_H

#include <math.h>
#include <string>
#include <sstream>
#include "MOOS/libMOOS/MOOSLib.h"
#include "MBUtils.h"
#include "AcousticStruct.cpp"

using namespace std; 

class AcousticCalculator{
public:
    AcousticCalculator(AcousticStruct&);
    virtual ~AcousticCalculator();
    bool solvePath(); 
    string pathString(); 
    string connectivityLocString(); 
    void setUsername(string v) {user = v;}; 

private:
   	double monkProfileSpeed(double);
   	void calcElevAngle(); 
   	void calcTransmissionLoss();
    
   	AcousticStruct info; //Contains all the parameters for calculating a path
   	double rvector; //r coordinate in cylindrical coordinates
   	double zdiff; //difference between vehicle depths
   	double elevAngle; //angle to transmit the sound ray in radians
   	double transmissionLoss; 
   	string user; 
};

#endif	/* ACOUSTICCALCULATOR_H */

