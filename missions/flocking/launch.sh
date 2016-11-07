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
LEADER="leader"                # The first vehicle Community
FOLLOWER1="follower1"          # The second vehicle Community
FOLLOWER2="follower2"          # etc
FOLLOWER3="follower3"
FOLLOWER4="follower4"
FOLLOWER5="follower5"
FOLLOWER6="follower6"
FOLLOWER7="follower7"
FOLLOWER8="follower9"
FOLLOWER9="follower9"
FOLLOWER10="follower10"

LEADER_POS="0,0"    
FOLLOWER_POS1="10,0"
FOLLOWER_POS2="20,0"
FOLLOWER_POS3="30,0"
FOLLOWER_POS4="40,0"
FOLLOWER_POS5="50,0"
FOLLOWER_POS6="60,0"
FOLLOWER_POS7="70,0"
FOLLOWER_POS8="80,0"
FOLLOWER_POS9="90,0"
FOLLOWER_POS10="100,0"

FOL="80,0"        
LOITER_POS1="x=0,y=-75"
SHORE_LISTEN="9300"

nsplug vehicle.moos targ_leader.moos -f WARP=$TIME_WARP    \
    VNAME=$LEADER    SHARE_LISTEN="9301"               \
    VPORT="9001"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$LEADER_POS           

nsplug vehicle.moos targ_follower1.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER1    SHARE_LISTEN="9302"            \
    VPORT="9002"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS1

nsplug vehicle.moos targ_follower2.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER2    SHARE_LISTEN="9303"            \
    VPORT="9003"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS2 

nsplug vehicle.moos targ_follower3.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER3    SHARE_LISTEN="9304"            \
    VPORT="9004"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS3 

nsplug vehicle.moos targ_follower4.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER4    SHARE_LISTEN="9305"            \
    VPORT="9005"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS4 

nsplug vehicle.moos targ_follower5.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER5    SHARE_LISTEN="9306"            \
    VPORT="9006"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS5 

nsplug vehicle.moos targ_follower6.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER6    SHARE_LISTEN="9307"            \
    VPORT="9007"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS6 

nsplug vehicle.moos targ_follower7.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER7    SHARE_LISTEN="9308"            \
    VPORT="9008"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS7 

nsplug vehicle.moos targ_follower8.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER8    SHARE_LISTEN="9309"            \
    VPORT="9009"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS8   

nsplug vehicle.moos targ_follower9.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER9    SHARE_LISTEN="9310"            \
    VPORT="9010"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS9     

nsplug vehicle.moos targ_follower10.moos -f WARP=$TIME_WARP  \
    VNAME=$FOLLOWER10    SHARE_LISTEN="9311"           \
    VPORT="9011"     SHORE_LISTEN=$SHORE_LISTEN            \
    START_POS=$FOLLOWER_POS10                  

nsplug shoreside.moos targ_shoreside.moos -f WARP=$TIME_WARP \
    SNAME="shoreside"  SHARE_LISTEN=$SHORE_LISTEN            \
    SPORT="9000"      

nsplug leader.bhv targ_leader.bhv -f VNAME=$LEADER     \
    START_POS=$LEADER_POS LOITER_POS=$LOITER_POS1       

nsplug follower.bhv targ_follower1.bhv -f VNAME=$FOLLOWER1     \
    START_POS=$FOLLOWER_POS1 LOITER_POS=$LOITER_POS1   

nsplug follower.bhv targ_follower2.bhv -f VNAME=$FOLLOWER2     \
    START_POS=$FOLLOWER_POS2 LOITER_POS=$LOITER_POS1   

nsplug follower.bhv targ_follower3.bhv -f VNAME=$FOLLOWER3     \
    START_POS=$FOLLOWER_POS3 LOITER_POS=$LOITER_POS1  

nsplug follower.bhv targ_follower4.bhv -f VNAME=$FOLLOWER4     \
    START_POS=$FOLLOWER_POS4 LOITER_POS=$LOITER_POS1  

nsplug follower.bhv targ_follower5.bhv -f VNAME=$FOLLOWER5     \
    START_POS=$FOLLOWER_POS5 LOITER_POS=$LOITER_POS1  

nsplug follower.bhv targ_follower6.bhv -f VNAME=$FOLLOWER6     \
    START_POS=$FOLLOWER_POS6 LOITER_POS=$LOITER_POS1  

nsplug follower.bhv targ_follower7.bhv -f VNAME=$FOLLOWER7     \
    START_POS=$FOLLOWER_POS7 LOITER_POS=$LOITER_POS1  

nsplug follower.bhv targ_follower8.bhv -f VNAME=$FOLLOWER8     \
    START_POS=$FOLLOWER_POS8 LOITER_POS=$LOITER_POS1  

nsplug follower.bhv targ_follower9.bhv -f VNAME=$FOLLOWER9     \
    START_POS=$FOLLOWER_POS9 LOITER_POS=$LOITER_POS1  

nsplug follower.bhv targ_follower10.bhv -f VNAME=$FOLLOWER10     \
    START_POS=$FOLLOWER_POS10 LOITER_POS=$LOITER_POS1  

if [ ! -e targ_leader.moos ]; then echo "no targ_leader.moos"; exit; fi
if [ ! -e targ_leader.bhv  ]; then echo "no targ_leader.bhv "; exit; fi
if [ ! -e targ_follower1.moos ]; then echo "no targ_follower1.moos"; exit; fi
if [ ! -e targ_follower1.bhv  ]; then echo "no targ_follower1.bhv "; exit; fi
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
printf "Launching the MOOS Community %s follower1 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
pAntler targ_follower1.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower2 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
pAntler targ_follower2.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower3 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
pAntler targ_follower3.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower4 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
pAntler targ_follower4.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower5 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
#pAntler targ_follower5.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower6 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
#pAntler targ_follower6.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower7 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
#pAntler targ_follower7.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower8 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
#pAntler targ_follower8.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower9 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
#pAntler targ_follower9.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &
printf "Launching the MOOS Community %s follower10 (WARP=%s) \n"  $COMMUNITY $TIME_WARP
#pAntler targ_follower10.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &

uMAC targ_shoreside.moos

printf "Killing all processes ... \n"
kill %1 
mykill
printf "Done killing processes.   \n"

