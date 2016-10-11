/* 
 * File:   ACOUSTICCALCULATOR.cpp
 * Author: sgfairbro
 * 
 * Created on October 2nd 2016
 */

#include "AcousticCalculator.h"

AcousticCalculator::AcousticCalculator(AcousticStruct& input) {
   info = input; 

   double xdiff = info.navXCollaborator - info.navX; 
   double ydiff = info.navYCollaborator - info.navY; 
   
   rvector = sqrt(xdiff*xdiff + ydiff*ydiff); 
   zdiff = info.navDepthCollaborator - info.navDepth; 

   //default username
   user = "sgfairbro"; 
}


AcousticCalculator::~AcousticCalculator() {
    
}

bool AcousticCalculator::solvePath(){

	calcElevAngle(); 
	calcTransmissionLoss();
	return true; 
}

//This function uses the Munk profile to calculate the speed of a ray of
//sound in the ocean. 
double AcousticCalculator::monkProfileSpeed(double depth){

	double epsilon = 0.00737; 
	double sofarChannelDepth = 1300;

	double scaledDepth = 2*(depth - scaledDepth) / scaledDepth;

	return 1500*(1+epsilon*(scaledDepth - 1 + exp(-scaledDepth))); 

}

//Let's start by assuming sound waves propogate as a straight line in the ocean.
//TODO - update this to use Snell's law
void AcousticCalculator::calcElevAngle(){

	elevAngle = (atan2(zdiff, rvector));

}


//TODO - use a finite difference approximation to calculate transmission loss
void AcousticCalculator::calcTransmissionLoss(){

	double crossSecArea = sqrt(rvector*rvector + zdiff*zdiff); 
	double speedFraction = monkProfileSpeed(info.navDepthCollaborator) / monkProfileSpeed(info.navDepth); 

	double ps = sqrt(abs(speedFraction*cos(elevAngle) / crossSecArea)); 

	transmissionLoss = -20*log10(ps);

}

string AcousticCalculator::pathString(){

	stringstream ss; 
	ss << "elev_angle=" << doubleToString((elevAngle*180/M_PI), 4) << ", "; 

	ss << "transmission_loss=" << doubleToString(transmissionLoss, 4) << ", "; 

	ss << "id=" << user << "."; 

	return ss.str(); 

}

//TODO - Find a new location to transmit if no path exists 
string AcousticCalculator::connectivityLocString(){
	return "x=xxx.xxx,y=yyy.yyy,depth=ddd.d,id=user@mit.edu."; 
}
