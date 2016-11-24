#!/bin/bash 


if [ -e ../../lib/liblab12codecs.so ]; then
    LD_EXTENSION="so"
elif [ -e ../../lib/liblab12codecs.dylib ]; then
    LD_EXTENSION="dylib"
else
    "Failed to determine dynamic library extension"
fi

# create
nsplug meta_receiver.moos targ_receiver.moos LD_EXTENSION=${LD_EXTENSION} -f
nsplug meta_sender.moos targ_sender.moos LD_EXTENSION=${LD_EXTENSION} -f 

#launch
pAntler targ_receiver.moos >& /dev/null&
pAntler targ_sender.moos >& /dev/null&