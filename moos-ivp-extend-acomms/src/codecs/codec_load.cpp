#include "codec_load.h"
#include "varint.h"
#include "arithmetic.h"

void goby_dccl_load(goby::acomms::DCCLCodec* dccl)
{
    goby::acomms::DCCLFieldCodecManager::add<VarIntCodec>("lab12_varint");
    goby::acomms::DCCLFieldCodecManager::add<ArithmeticCodec>("lab12_arithmetic");
}

