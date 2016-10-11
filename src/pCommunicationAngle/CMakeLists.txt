#--------------------------------------------------------
# The CMakeLists.txt for:                       pCommunicationAngle
# Author(s):                              Shane Fairbrother
#--------------------------------------------------------

# FILE(GLOB SRC *.cpp)

SET(SRC
  CommunicationAngle.cpp
  CommunicationAngle_Info.cpp
  AcousticCalculator.cpp
  AcousticStruct.cpp
  main.cpp
)



ADD_EXECUTABLE(pCommunicationAngle ${SRC})

TARGET_LINK_LIBRARIES(pCommunicationAngle
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

