if (NOT WIN32)
  return()
endif()

add_executable(iitdvpnagent ovpnagent.cpp)
add_core_dependencies(iitdvpnagent)
add_json_library(iitdvpnagent)
option(ENABLE_AGENT_FILE_LOG "Enable writing agent.log file" OFF)

if (NOT ENABLE_AGENT_FILE_LOG)
  target_compile_definitions(iitdvpnagent PRIVATE OVPN_AGENT_NO_FILE_LOG)
endif()

target_compile_definitions(iitdvpnagent PRIVATE -DOVPNAGENT_DISABLE_PATH_CHECK)
