/************************************************************/
/*    NAME: Toby Schneider                                  */
/*    ORGN: MIT                                             */
/*    FILE: arithmetic.h                                    */
/*    DATE: 2012-03-12                                      */
/************************************************************/

#ifndef ARITHMETICH
#define ARITHMETICH

#include <limits>
#include <cstdlib>

#include "goby/acomms/dccl.h" // for Bitset, DCCLTypedFieldCodec
#include "goby/util/sci.h" // for ceil_log2
#include "goby/util/primitive_types.h" // for goby::uint32, etc

using namespace std; 

//#define ARITHMETIC_TEST

class ArithmeticCodec :
    public goby::acomms::DCCLRepeatedTypedFieldCodec<goby::int32>
{
  public:
    ArithmeticCodec()
    {
        // hard-code probability table for this lab example
        symbol_probabilities_[10] = 0.71;
        for(int i = 11; i < 20; ++i)
            symbol_probabilities_[i] = 0.02;
        symbol_probabilities_[20] = 0.11;
        
        best_case_probability_ = 0.71;
        worst_case_probability_ = 0.02;        

        // tests the functionality of bits_to_range
        // and range_to_bits using 1000 random values
#ifdef ARITHMETIC_TEST        
        srand ( time(NULL) );
        // TESTING
        for(int i = 1; i < 1000; ++i)
        {
            double a = static_cast<double>(rand()) / RAND_MAX;
            double b = static_cast<double>(rand()) / RAND_MAX;
            double lower, upper;

            if(a == b)
                continue;

            lower = (a < b) ? a : b;
            upper = (a < b) ? b : a;

            goby::acomms::Bitset bits = range_to_bits(std::make_pair(lower, upper));
            
            std::pair<double, double> result = bits_to_range(bits);
            
            std::cout << i << ": " << std::setprecision(15)
                      << "in: [" << lower
                      << ", " << upper
                      << "), out: [" 
                      << result.first << "," << result.second << ")"
                      << ", bits: " << bits 
                      << ", entropy (lower bound) size: " <<goby::util::ceil_log2(1/(upper-lower)) << std::endl; 
            

            assert(lower <= result.first);
            assert(upper > result.second);
        }

#endif
    }
    
private:
    //
    // virtual methods from goby::acomms::DCCLRepeatedTypedFieldCodec<goby::int32>
    //

    // Encode this field using an arithmetic coder given the vector of integers in `wire_values`
    // Returns a set of bits represented the encoded field. Bitset is a typedef for boost::dynamic_bitset<unsigned char>
    // You shouldn't need to worry about the details of Bitset.
    // Use ArithmeticCodec::range_to_bits defined for you to convert
    // ** YOU MUST IMPLEMENT THIS METHOD **
    goby::acomms::Bitset encode_repeated(const std::vector<goby::int32>& wire_values);


    // Decode this field using the same arithmetic coder used to encode it.
    // Don't worry about the details of Bitset, use ArithmeticCodec::bits_to_range
    // to get a decimal representation of the binary range in `bits`.
    // ** YOU MUST IMPLEMENT THIS METHOD **
    std::vector<goby::int32> decode_repeated(goby::acomms::Bitset* bits);


    // the maximum number of bits required to encode any field using this codec
    // in our case, this message will be the least probable set of symbols,
    // such as temperature = [11, 12, 13, 14, 15]
    // this maximum size will be upper bounded by: ceil(log_2(1/P)) + 1 where P is the
    // probability of this least probable set of symbols
    // ** YOU MUST IMPLEMENT THIS METHOD **
    unsigned max_size_repeated()
    {
        int m = max_repeat(); // number of symbols in the file
        return goby::util::ceil_log2(1/(std::pow(worst_case_probability_, m))) + 1;
    }
    
    // the minimum number of bits required to encode any field using this codec
    // in our case, this message will be the most probable set of symbols,
    // that is temperature = [10, 10, 10, 10, 10]
    // ** YOU MUST IMPLEMENT THIS METHOD **
    unsigned min_size_repeated()
    {
        int m = max_repeat(); // number of symbols in the file
        return goby::util::ceil_log2(1/(std::pow(best_case_probability_, m)));
    }

    enum { LARGEST_MAX_REPEAT_SIZE = 5 };
    
    // validates the (goby.field) parameters for this codec in the .proto file
    // ** this method has been implemented for you **
    void validate();

    // returns the encoded size of this field given these values
    // ** this method has been implemented for you **
    // (inefficiently in this case by actually encoding the field
    // and seeing what the size is)
    unsigned size_repeated(const std::vector<goby::int32>& field_values);

    
    //
    // normal (not inherited) methods
    //
    
    // the maximum number of repeated values (size of the vector). Same as (goby.field).dccl.max_repeat field in the protobuf file.
    // ** this method has been implemented for you **
    goby::int32 max_repeat() { return DCCLFieldCodecBase::dccl_field_options().max_repeat(); }

    // calculate the bits required to minimally and uniquely represent the decimal range
    // bounded by [range.first, range.second)
    // 
    // the return value is given as a binary decimal, where the least significant bit
    // in the bitset (index 0) represents 2^-1, the next most significant bit (index 1) is 2^-2, and so on
    // ** this method has been implemented for you **
    goby::acomms::Bitset range_to_bits(std::pair<double, double> range);

    // converts a Bitset `bits` created by ArithmeticCodec::range_to_bits back into the range [return.first, return.second)
    // uniquely represented by the set of bits. This range is, in general, a proper subset of the
    // original range passed to ArithmeticCodec::range_to_bits.
    // ** this method has been implemented for you **
    std::pair<double, double> bits_to_range(goby::acomms::Bitset bits);
    
  private:
    std::map<int, double> symbol_probabilities_;
    double worst_case_probability_;
    double best_case_probability_;
    
};


#endif
