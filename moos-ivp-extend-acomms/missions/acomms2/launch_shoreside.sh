#!/bin/bash 

if [ -e ../../lib/liblab12codecs.so ]; then
    LD_EXTENSION="so"
elif [ -e ../../lib/liblab12codecs.dylib ]; then
    LD_EXTENSION="dylib"
else
    "Failed to determine dynamic library extension"
fi

# create
nsplug meta_shoreside.moos targ_shoreside.moos LD_EXTENSION=${LD_EXTENSION} -f

#launch
pAntler targ_shoreside.moos >& /dev/null&
