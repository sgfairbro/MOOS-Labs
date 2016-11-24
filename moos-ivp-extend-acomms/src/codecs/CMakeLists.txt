add_library(lab12codecs SHARED varint.cpp arithmetic.cpp codec_load.cpp)
target_link_libraries(lab12codecs ${Boost_LIBRARIES} ${GOBY_LIBRARIES} ${PROTOBUF_LIBRARIES})

