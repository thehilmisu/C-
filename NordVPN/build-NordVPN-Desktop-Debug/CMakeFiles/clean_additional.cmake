# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/NordVPN_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/NordVPN_autogen.dir/ParseCache.txt"
  "NordVPN_autogen"
  )
endif()
