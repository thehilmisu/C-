cmake_minimum_required(VERSION 3.5)

set(ApplicationName "capstats")
project(${ApplicationName} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

FetchContent_Declare(
  libpcap
  GIT_REPOSITORY https://github.com/the-tcpdump-group/libpcap.git
  GIT_TAG        libpcap-1.10.0
  CMAKE_ARGS     "-Wno-dev"
)
FetchContent_MakeAvailable(libpcap)

FetchContent_GetProperties(libpcap)
if(NOT libpcap_POPULATED)
  FetchContent_Populate(libpcap)
  add_subdirectory(${libpcap_SOURCE_DIR} ${libpcap_BINARY_DIR})
endif()


list(APPEND ApplicationHeaders
)

list(APPEND ApplicationSources
  main.cpp
)

list(APPEND OtherFiles
  README.md
)

add_executable(${ApplicationName} ${ApplicationSources} ${ApplicationHeaders})

add_custom_target(other-files SOURCES ${OtherFiles})


include_directories(${libpcap_SOURCE_DIR})


list(APPEND ApplicationNeededLibraries
  pthread
  pcap
)
find_library(NAMES ${ApplicationNeededLibraries})

link_directories(${libpcap_BINARY_DIR})

target_link_libraries(${ApplicationName} ${ApplicationNeededLibraries})

source_group(
  TREE "${CMAKE_CURRENT_SOURCE_DIR}"
  PREFIX "Header Files"
  FILES ${ApplicationHeaders}
)
source_group(
  TREE "${CMAKE_CURRENT_SOURCE_DIR}"
  PREFIX "Source Files"
  FILES ${ApplicationSources}
)
