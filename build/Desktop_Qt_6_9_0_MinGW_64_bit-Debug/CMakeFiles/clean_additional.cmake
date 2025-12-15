# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\siakad_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\siakad_autogen.dir\\ParseCache.txt"
  "siakad_autogen"
  )
endif()
