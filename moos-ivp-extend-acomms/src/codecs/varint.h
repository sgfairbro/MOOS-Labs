/************************************************************/
/*    NAME: Toby Schneider                                  */
/*    ORGN: MIT                                             */
/*    FILE: varint.h                                        */
/*    DATE: 2012-03-12                                      */
/************************************************************/

#ifndef VARINTH
#define VARINTH

#include "goby/acomms/dccl.h" // DCCL
#include "goby/util/as.h" // for goby::util::as<>()
#include "goby/util/primitive_types.h" // for goby::uint32, etc
 
/// \brief Provides a 1 byte or 2 byte variable integer codec for
// encoding numbers from 0 to 2^15. Uses 1 byte for 0-127, 2 bytes otherwise
class VarIntCodec : public goby::acomms::DCCLTypedFieldCodec<goby::uint32>
{
private:
    // encode given no value
    goby::acomms::Bitset encode();
    // encode given a value
    goby::acomms::Bitset encode(const goby::uint32& wire_value);

    // decode given a set of bits
    goby::uint32 decode(goby::acomms::Bitset* bits);

    // size of the field with no value
    unsigned size();
    // size of the field given a value
    unsigned size(const goby::uint32& field_value);

    // worst case size
    unsigned max_size();

    // best case size
    unsigned min_size();

    // validate any option extensions needed
    void validate() { }
            
    // maximum int we can fit in short or long form
    enum { ONE_BYTE_MAX_INT = (1 << 7) - 1,
           TWO_BYTE_MAX_INT = (1 << 15) - 1};
            
    enum { SHORT_FORM_INT_BYTES = 1,
           LONG_FORM_INT_BYTES = 2 };

    enum { BITS_IN_BYTE = 8 };
    
};


#endif
