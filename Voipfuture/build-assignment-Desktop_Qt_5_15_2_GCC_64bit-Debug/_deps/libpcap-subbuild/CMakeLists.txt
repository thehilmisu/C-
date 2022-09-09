# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.19.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(libpcap-populate NONE)

include(ExternalProject)
ExternalProject_Add(libpcap-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/the-tcpdump-group/libpcap.git" "GIT_TAG" "libpcap-1.10.0" "CMAKE_ARGS" "-Wno-dev"
                    SOURCE_DIR          "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-src"
                    BINARY_DIR          "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


