# CMakeList.txt : CMake project for HelloTriangle-Assignment1-GPR200, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (HelloTriangle-Assignment1-GPR200 "HelloTriangle-Assignment1-GPR200.cpp" "HelloTriangle-Assignment1-GPR200.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HelloTriangle-Assignment1-GPR200 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
