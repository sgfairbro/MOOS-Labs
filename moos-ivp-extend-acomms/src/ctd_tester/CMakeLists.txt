add_executable(ctd_tester main.cpp)
target_link_libraries(ctd_tester ${GOBY_LIBRARIES} lab12codecs lab12messages ${PROTOBUF_LIBRARIES})