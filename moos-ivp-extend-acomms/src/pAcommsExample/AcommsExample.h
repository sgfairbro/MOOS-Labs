/************************************************************/
/*    NAME: Toby Schneider                                  */
/*    ORGN: MIT                                             */
/*    FILE: AcommsExample.h                                 */
/*    DATE: 2012-03-12                                      */
/************************************************************/

#ifndef AcommsExample_HEADER
#define AcommsExample_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "acomms_example.pb.h"

class AcommsExample : public CMOOSApp
{
 public:
   AcommsExample();
   ~AcommsExample() { }
   

  private:
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();

  private:
   double start_time_;
   double post_interval1_;
   double post_interval2_;
   std::string out_moos_var1_;
   std::string out_moos_var2_;
};

#endif 
