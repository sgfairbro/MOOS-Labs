/************************************************************/
/*    NAME: Toby Schneider                                  */
/*    ORGN: MIT                                             */
/*    FILE: AcommsExample_ExampleConfig.cpp                 */
/*    DATE: 2012-03-12                                      */
/************************************************************/

#include <iostream>
#include "AcommsExample_ExampleConfig.h"
#include "ColorParse.h"

using namespace std;

//----------------------------------------------------------------
// Procedure: showExampleConfig                                  

void showExampleConfig()
{
  cout << "                                                   " << endl;
  cout << "===================================================" << endl;
  cout << "pAcommsExample Example MOOS Configuration                " << endl;
  cout << "===================================================" << endl;
  cout << "                                                   " << endl;
  cout << "ProcessConfig = pAcommsExample                           " << endl;
  cout << "{                                                  " << endl;
  cout << "  AppTick   = 4                                    " << endl;
  cout << "  CommsTick = 4                                    " << endl;
  cout << "                                                   " << endl;
}
