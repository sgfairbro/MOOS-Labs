protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${CMAKE_CURRENT_BINARY_DIR} 
  acomms_example.proto
  mini_command.proto
  ctd_default.proto
  ctd.proto)
add_library(lab12messages SHARED ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(lab12messages ${PROTOBUF_LIBRARIES} ${GOBY_LIBRARIES})