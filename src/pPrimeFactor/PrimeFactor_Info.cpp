/****************************************************************/
/*   NAME: Shane Fairbrother                                             */
/*   ORGN: MIT Cambridge MA                                     */
/*   FILE: PrimeFactor_Info.cpp                               */
/*   DATE: September 23rd, 2016                                    */
/****************************************************************/

#include <cstdlib>
#include <iostream>
#include "PrimeFactor_Info.h"
#include "ColorParse.h"
#include "ReleaseInfo.h"

using namespace std;

//----------------------------------------------------------------
// Procedure: showSynopsis

void showSynopsis()
{
  blk("SYNOPSIS:                                                       ");
  blk("-------------------------------------------------------------------------------");
  blk("The pPrimeFactor application is used for calculating the prime factorization");
  blk("of 64-bit integers. Variables posted with the name NUM_VALUE will be ");
  blk("factored by the program. Incoming NUM_VALUE variables are assumed to be ");
  blk("strings. Non-integer values will be truncated and factored. The factorization ");
  blk("results are posted to the variable PRIME_RESULT.");
  blk("                                                                ");
  blk("Besides Apptick and Commstick, the inputs to the pPrimeFactor application");
  blk("are USERNAME and STEPS. USERNAME allows the displayed username in"); 
  blk("PRIME_RESULT to be customized. STEPS is the number of steps used to factor");  
  blk("a number before proceeding to the next number. A larger number of steps ");
  blk("will cause the program to spend more processing time factoring larger numbers.");
  blk("A smaller number of steps will cause pPrimeFactor to save larger numbers for");
  blk("later and factor smaller ones in between the calculation of large number");
  blk("factorization. The default value of STEPS is 1000.");
  blk("--------------------------------------------------------------------------------");
  blk("                                                                ");
}

//----------------------------------------------------------------
// Procedure: showHelpAndExit

void showHelpAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("Usage: pPrimeFactor file.moos [OPTIONS]                   ");
  blu("=============================================================== ");
  blk("                                                                ");
  showSynopsis();
  blk("                                                                ");
  blk("Options:                                                        ");
  mag("  --alias","=<ProcessName>                                      ");
  blk("      Launch pPrimeFactor with the given process name         ");
  blk("      rather than pPrimeFactor.                           ");
  mag("  --example, -e                                                 ");
  blk("      Display example MOOS configuration block.                 ");
  mag("  --help, -h                                                    ");
  blk("      Display this help message.                                ");
  mag("  --interface, -i                                               ");
  blk("      Display MOOS publications and subscriptions.              ");
  mag("  --version,-v                                                  ");
  blk("      Display the release version of pPrimeFactor.        ");
  blk("                                                                ");
  blk("Note: If argv[2] does not otherwise match a known option,       ");
  blk("      then it will be interpreted as a run alias. This is       ");
  blk("      to support pAntler launching conventions.                 ");
  blk("                                                                ");
  exit(0);
}

//----------------------------------------------------------------
// Procedure: showExampleConfigAndExit

void showExampleConfigAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("pPrimeFactor Example MOOS Configuration                   ");
  blu("=============================================================== ");
  blk("                                                                ");
  blk("ProcessConfig = pPrimeFactor                              ");
  blk("{                                                               ");
  blk("  AppTick   = 4                                                 ");
  blk("  CommsTick = 4                                                 ");
  blk("  USERNAME = SGFAIRBRO                                    ");
  blk("  STEPS = 1000                                                   ");
  blk("}                                                                ");
  blk("                                                                ");
  exit(0);
}


//----------------------------------------------------------------
// Procedure: showInterfaceAndExit

void showInterfaceAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("pPrimeFactor INTERFACE                                    ");
  blu("=============================================================== ");
  blk("                                                                ");
  showSynopsis();
  blk("                                                                ");
  blk("SUBSCRIPTIONS:                                                  ");
  blk("------------------------------------                            ");
  blk("NUM_VALUE - string representation of a 64-bit integer                                               ");
  blk("                                                                ");
  blk("PUBLICATIONS:                                                   ");
  blk("------------------------------------                            ");
  blk("PRIME_RESULT - the resulting prime factorization of NUM_VALUE. ");
  blk("Also includes the original number, received and calculated indices, solve time,");
  blk("and username."); 
  blk("e.g.  PRIME_RESULT = ""orig=30030,received=34,calculated=33,solve_time=2.03,");
  blk("primes=2:3:5:7:11:13,username=jane""                                                                ");
  blk("                                                                ");
  exit(0);
}

//----------------------------------------------------------------
// Procedure: showReleaseInfoAndExit

void showReleaseInfoAndExit()
{
  showReleaseInfo("pPrimeFactor 1.0 by Shane Fairbrother", "gpl");
  exit(0);
}

