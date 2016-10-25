cmake_minimum_required (VERSION 2.8.10)
project (sandbox)

include_directories(${PROJECT_SOURCE_DIR}/src)

find_package(LibXml2)
if (LIBXML2_FOUND)
  include_directories(${LIBXML2_INCLUDE_DIR})
  link_directories(${LIBXML2_LIBRARIES})
endif(LIBXML2_FOUND)

#INCLUDE(CMake/FindLibxml2QMC.cmake)
#
#IF(LIBXML2_FOUND)
#  INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})
#  SET(HAVE_LIBXML2 1)
#  SET(QMC_UTIL_LIBS ${QMC_UTIL_LIBS} ${LIBXML2_LIBRARIES})
#ELSE()
#  MESSAGE(FATAL_ERROR "Missing Libxml2")
#ENDIF(LIBXML2_FOUND)

# build library
set(XML_UTILS
  src/OhmmsData/Libxml2Doc.cpp
)
add_library(xmlutils ${XML_UTILS})

add_executable(sandbox ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(sandbox xml2 xmlutils)
