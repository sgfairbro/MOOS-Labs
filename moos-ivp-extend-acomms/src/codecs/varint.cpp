/************************************************************/
/*    NAME: Toby Schneider                                  */
/*    ORGN: MIT                                             */
/*    FILE: varint.cpp                                      */
/*    DATE: 2012-03-12                                      */
/************************************************************/

#include "varint.h"

goby::acomms::Bitset VarIntCodec::encode()
{
    return encode(0);
}

goby::acomms::Bitset VarIntCodec::encode(const goby::uint32& id)
{
    if(id <= ONE_BYTE_MAX_INT) // short form, id = [0, 128)
    {
        // e.g. id = d50 = 0110010
        // then, id << 1 = 01100100
        return(goby::acomms::Bitset(size(id), id << 1));
    }                
    else // long form, id = [128, 32768)
    {
        // e.g. d500: return_bits = 000000111110100
        goby::acomms::Bitset return_bits(size(id), id);
        // e.g. return_bits = 0000001111101000
        return_bits <<= 1; 
        // set least significant bit (LSB) to indicate long form
        // e.g. return_bits = 0000001111101001
        return_bits.set(0); // sets bit 0 to true
        return return_bits; 
    }
}

goby::uint32 VarIntCodec::decode(goby::acomms::Bitset* bits)
{
    // example 1: d50, bits = 01100100
    // example 2: d500, bits = 11101001
    if(bits->test(0)) // true if bit 0 is true (==1)
    {
        // long header
        // grabs more bits to add to the MSBs of `bits`
        // example 2: bits is now = 0000001111101001
        bits->get_more_bits((LONG_FORM_INT_BYTES - SHORT_FORM_INT_BYTES)*BITS_IN_BYTE);
        return bits->to_ulong() >> 1; // bit-shift back to d500
    }
    else
    {
        // short header
        return bits->to_ulong() >> 1; // bit-shift back to d50
    }
}

unsigned VarIntCodec::size()
{
    return size(0);
}

unsigned VarIntCodec::size(const goby::uint32& id)
{
    if(id > TWO_BYTE_MAX_INT)
        throw(goby::acomms::DCCLException("dccl.id provided (" + goby::util::as<std::string>(id) + ") is less than 0 or exceeds maximum: " + goby::util::as<std::string>(int(TWO_BYTE_MAX_INT))));
    
    return (id <= ONE_BYTE_MAX_INT) ?
        SHORT_FORM_INT_BYTES*BITS_IN_BYTE :
        LONG_FORM_INT_BYTES*BITS_IN_BYTE;

}

unsigned VarIntCodec::max_size()
{
    return LONG_FORM_INT_BYTES * BITS_IN_BYTE;
}

unsigned VarIntCodec::min_size()
{
    return SHORT_FORM_INT_BYTES * BITS_IN_BYTE;
}
