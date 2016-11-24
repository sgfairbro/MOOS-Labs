
#ifndef CODEC_LOAD_H
#define CODEC_LOAD_H

#include "goby/acomms/dccl/dccl.h"

extern "C"
{
    void goby_dccl_load(goby::acomms::DCCLCodec* dccl);
}

#endif
