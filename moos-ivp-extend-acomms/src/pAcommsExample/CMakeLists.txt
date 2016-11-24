#--------------------------------------------------------
# The CMakeLists.txt for:                       pAcommsExample
# Author(s):                              
#--------------------------------------------------------

add_executable(pAcommsExample
  AcommsExample.cpp AcommsExample_ExampleConfig.cpp main.cpp
  ${PROTO_SRCS}
  ${PROTO_HDRS}
  )

target_link_libraries(pAcommsExample
  ${MOOS_LIBRARIES}
   mbutil
   lab12codecs
   lab12messages
   ${GOBY_LIBRARIES}
   ${PROTOBUF_LIBRARIES})

