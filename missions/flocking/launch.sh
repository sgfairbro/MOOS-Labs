#!/bin/bash -e
COMMUNITY="flock"

#-------------------------------------------------------
#  Part 1: Check for and handle command-line arguments
#-------------------------------------------------------
TIME_WARP=1
for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
    printf "%s [SWITCHES] [time_warp]   \n" $0
    printf "  --help, -h         \n" 
    exit 0;
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$TIME_WARP" = 1 ]; then 
        TIME_WARP=$ARGI
    else 
    printf "Bad Argument: %s \n" $ARGI
    exit 0
    fi
done

#-------------------------------------------------------
#  Part 2: Create the .moos and .bhv files. 
#-------------------------------------------------------
VNAME1="leader"           # The first vehicle Community
VNAME2="follower"           # The second vehicle Community
START_POS1="0,0"         
START_POS2="80,0"        
LOITER_POS1="x=0,y=-75"
LOITER_POS2="x=125,y=-50"
SHORE_LISTEN="9300"

nsplug vehicle.moos targ_leader.moos -f WARP=$TIME_WARP \
    VNAME=$VNAME1    SHARE_LISTEN="9301"               \
    VPORT="9001"     SHORE_LISTEN=$SHORE_LISTEN        \
    START_POS=$START_POS1             

nsplug vehicle.moos targ_follower.moos -f WARP=$TIME_WARP \
    VNAME=$VNAME2    SHARE_LISTEN="9302"                   \
    VPORT="9002"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$START_POS2                

nsplug shoreside.moos targ_shoreside.moos -f WARP=$TIME_WARP \
    SNAME="shoreside"  SHARE_LISTEN=$SHORE_LISTEN            \
    SPORT="9000"      

nsplug leader.bhv targ_leader.bhv -f VNAME=$VNAME1     \
    START_POS=$START_POS1 LOITER_POS=$LOITER_POS1       

nsplug follower.bhv targ_follower.bhv -f VNAME=$VNAME2     \
    START_POS=$START_POS2 LOITER_POS=$LOITER_POS1   

if [ ! -e targ_leader.moos ]; then echo "no targ_leader.moos"; exit; fi
if [ ! -e targ_leader.bhv  ]; then echo "no targ_leader.bhv "; exit; fi
if [ ! -e targ_follower.moos ]; then echo "no targ_follower.moos"; exit; fi
if [ ! -e targ_follower.bhv  ]; then echo "no targ_follower.bhv "; exit; fi
if [ ! -e targ_shoreside.moos ]; then echo "no targ_shoreside.moos";  exit; fi

if [ ${JUST_MAKE} = "yes" ] ; then
    exit 0
fi

#-------------------------------------------------------
#  Part 3: Launch the processes
#-------------------------------------------------------
printf "Launching $SNAME MOOS Community (WARP=%s) \n"  $TIME_WARP
pAntler targ_shoreside.moos >& /dev/null &
printf "Launching the MOOS Community %s leader (WARP=%s) \n"  $COMMUNITY $TIME_WARP
pAntler targ_leader.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower (WARP=%s) \n"  $COMMUNITY $TIME_WARP
pAntler targ_follower.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &

uMAC targ_shoreside.moos

printf "Killing all processes ... \n"
kill %1 
mykill
printf "Done killing processes.   \n"

