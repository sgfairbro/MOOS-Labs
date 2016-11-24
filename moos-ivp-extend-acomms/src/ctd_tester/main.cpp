#include "goby/acomms/dccl.h" // for goby::acomms::DCCLCodec
#include "codecs/codec_load.h" 
#include "ctd.pb.h" // for CTDMessage
#include "ctd_default.pb.h" // for CTDMessageDefault
#include "acomms_example.pb.h"
#include <cstdlib> // for rand
#include <google/protobuf/text_format.h> // for TextFormat
#include "goby/util/sci.h" //

void run_test(const std::vector<double>& temperatures);
int random_temperature();
std::string print_message(const google::protobuf::Message& msg);

int main(int argc, char* argv[])
{
    goby::acomms::DCCLCodec* dccl = goby::acomms::DCCLCodec::get();
    goby_dccl_load(dccl);
    dccl->validate<CTDMessage>();
    dccl->info<CTDMessage>(&std::cout);

    std::vector<double> temp1;
    temp1.push_back(19);
    temp1.push_back(19);
    temp1.push_back(18);
    temp1.push_back(17);
    temp1.push_back(17);
    
    run_test(temp1);

    std::vector<double> temp2;
    temp2.push_back(10);
    temp2.push_back(10);
    temp2.push_back(10);
    temp2.push_back(10);
    temp2.push_back(10);
    
    run_test(temp2);

    // seed random
    srand (time(0));
    int test_count = 10;
    for(int i = 0; i < test_count; ++i)
    {
        std::vector<double> temprand;
        for(int j = 0; j < 5; ++j)
            temprand.push_back(random_temperature());
        run_test(temprand);
    }
    
    std::cout << "all tests passed" << std::endl;
}

void run_test(const std::vector<double>& temperatures)
{
    static int i = 0;
    
    goby::acomms::DCCLCodec* dccl = goby::acomms::DCCLCodec::get();

    CTDMessage msg_in1, msg_out1;
    msg_in1.add_depth(12);
    msg_in1.add_depth(13);
    msg_in1.add_depth(14);
    msg_in1.add_depth(13);
    msg_in1.add_depth(13);
    
    for(int i = 0, n = temperatures.size(); i < n; ++i)
        msg_in1.add_temperature(temperatures[i]);

    msg_in1.add_salinity(30.09);
    msg_in1.add_salinity(30.10);
    msg_in1.add_salinity(30.11);
    msg_in1.add_salinity(30.12);
    msg_in1.add_salinity(30.13);
    
    CTDMessageDefault msg_comparison;
    // this *only* works because the core protobuf fields are the same
    // don't try this at home :)
    msg_comparison.ParseFromString(msg_in1.SerializeAsString());    
    
    std::cout << std::setw(30) << std::setfill('*')  << " BEGIN TEST " << i
              << " " << std::setw(20) << std::setfill('*') << " "
              << std::endl;    
    
    std::cout << "In: " << print_message(msg_in1) << std::endl;    
    
    std::string bytes1;
    std::cout << "Try encode ..." << std::endl;
    dccl->encode(&bytes1, msg_in1); // ENCODE
    std::cout << "Encoded (hex): " << goby::util::hex_encode(bytes1) << std::endl;
    std::cout << "Size (bytes): " << bytes1.size() << std::endl;
    std::cout << "Default codec size (bytes): " << dccl->size(msg_comparison) << std::endl;
    
    std::cout << "Try decode..." << std::endl;
    dccl->decode(bytes1, &msg_out1); // DECODE
    std::cout << "Out: " << print_message(msg_out1) << std::endl;

    // assert that the decoded message is the same as the encoded message
    assert(msg_in1.SerializeAsString() == msg_out1.SerializeAsString()); 

    std::cout << std::setw(30) << std::setfill('*')
              << " PASSED TEST " << i++
              << " " << std::setw(20) << std::setfill('*') << " \n"
              << std::endl;

}

// gives random values from
// same distribution that we will see on real vehicle
int random_temperature()
{
    int depth = rand() % 100;
    if(depth > 30)
        return 10;
    else if(depth <= 30 && depth > 10)
        return goby::util::unbiased_round(10 + (30-depth)/2, 0);
    else
        return 20;
}

// write a succint textual representation of the protobuf message `msg` to the return string
std::string print_message(const google::protobuf::Message& msg)
{
    google::protobuf::TextFormat::Printer printer;
    printer.SetSingleLineMode(true);
    printer.SetUseShortRepeatedPrimitives(true);
    std::string out;
    printer.PrintToString(msg, &out);
    return out;
}
