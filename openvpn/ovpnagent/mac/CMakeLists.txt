if (NOT APPLE)
  return()
endif()

add_executable(iitdvpnagent ovpnagent.cpp)
add_core_dependencies(iitdvpnagent)
add_json_library(iitdvpnagent)

# Avoid deprecated warning for using daemon
target_compile_options(iitdvpnagent PRIVATE -Wno-deprecated-declarations)
