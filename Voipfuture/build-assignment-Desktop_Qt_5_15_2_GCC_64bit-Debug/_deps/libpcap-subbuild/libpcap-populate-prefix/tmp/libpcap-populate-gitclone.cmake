
if(NOT "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-subbuild/libpcap-populate-prefix/src/libpcap-populate-stamp/libpcap-populate-gitinfo.txt" IS_NEWER_THAN "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-subbuild/libpcap-populate-prefix/src/libpcap-populate-stamp/libpcap-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-subbuild/libpcap-populate-prefix/src/libpcap-populate-stamp/libpcap-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/the-tcpdump-group/libpcap.git" "libpcap-src"
    WORKING_DIRECTORY "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/the-tcpdump-group/libpcap.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout libpcap-1.10.0 --
  WORKING_DIRECTORY "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'libpcap-1.10.0'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-subbuild/libpcap-populate-prefix/src/libpcap-populate-stamp/libpcap-populate-gitinfo.txt"
    "/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-subbuild/libpcap-populate-prefix/src/libpcap-populate-stamp/libpcap-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/thehilmisu/Desktop/Workdir/Voipfuture/build-assignment-Desktop_Qt_5_15_2_GCC_64bit-Debug/_deps/libpcap-subbuild/libpcap-populate-prefix/src/libpcap-populate-stamp/libpcap-populate-gitclone-lastrun.txt'")
endif()

