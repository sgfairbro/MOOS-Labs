#--------------------------------------------------------
# The CMakeLists.txt for:                 pCoroner
# Author(s):                                 t. schneider
#--------------------------------------------------------

FILE(GLOB SRC *.cpp)

ADD_EXECUTABLE(pCoroner ${SRC})
      
TARGET_LINK_LIBRARIES(pCoroner
  mbutil
  ${MOOS_LIBRARIES}
  )
