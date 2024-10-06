# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\calculadora_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\calculadora_autogen.dir\\ParseCache.txt"
  "calculadora_autogen"
  )
endif()
