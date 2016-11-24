##############################################################################
# FILE:        moos-ivp-extend/src/CMakeLists.txt
# DATE:        2010/09/07
# DESCRIPTION: CMakeLists.txt file for the moos-ivp-extend source directory
##############################################################################

# needs to happen before (directories above) anyone needs Google Protobuf
find_package(ProtobufLocal REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

# tells protoc where to look for proto files
protobuf_include_dirs(${CMAKE_SOURCE_DIR}/src/protobuf)

# where we'll put the generated pb.h and pb.cc
include_directories(${CMAKE_BINARY_DIR}/src/protobuf)

find_package(Boost COMPONENTS signals system) 

find_package(Goby REQUIRED)
include_directories(${GOBY_INCLUDE_DIRS})
protobuf_include_dirs(${GOBY_INCLUDE_DIRS})

#============================================================================
# Add the libraries in the current directory to the include path
#============================================================================
FILE(GLOB LOCAL_LIBRARY_DIRS ./lib_*)
INCLUDE_DIRECTORIES(${LOCAL_LIBRARY_DIRS})

# for other libraries
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

#============================================================================
# List the subdirectories to build...
#============================================================================
ADD_SUBDIRECTORY(ctd_tester)
ADD_SUBDIRECTORY(protobuf)
ADD_SUBDIRECTORY(codecs)
ADD_SUBDIRECTORY(pAcommsExample)
ADD_SUBDIRECTORY(pCoroner)

##############################################################################
#                           END of CMakeLists.txt
##############################################################################
