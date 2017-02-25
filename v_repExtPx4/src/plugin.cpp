#include "plugin.h"

#include <cassert>
#include <cstring>

#include <iostream>
#include <string>

#include <vrep/scriptFunctionData.h>
#include <vrep/v_repLib.h>

#include "mavlink_server.h"

#ifdef _WIN32
  #ifdef QT_COMPIL
    #include <direct.h>
  #else
    #include <shlwapi.h>
    #pragma comment(lib, "Shlwapi.lib")
  #endif
#endif /* _WIN32 */
#if defined (__linux) || defined (__APPLE__)
  #include <unistd.h>
  #define WIN_AFX_MANAGE_STATE
#endif /* __linux || __APPLE__ */

namespace {

// TODO(kgreenek): Pass this in from cmake-generated config file.
const std::string kPluginName = "PX4";
// TODO(kgreenek): Pass this in from cmake-generated config file.
constexpr int kMinVrepVersion = 30200;

LIBRARY vrep_lib;
std::unique_ptr<MavlinkServer> mavlink_server;

void PrintInfo(std::string message) {
  std::cout << "INFO (" << kPluginName << "): " << message << std::endl;
}

void PrintError(std::string message) {
  std::cout << "ERROR (" << kPluginName << "): " << message << std::endl;
}

std::string VrepLibPath() {
  constexpr int kMaxPathLength = 1024;
  char path_c_str[kMaxPathLength];
  memset(path_c_str, 0, sizeof(path_c_str));
  #ifdef _WIN32
    #ifdef QT_COMPIL
      _getcwd(path_c_str, sizeof(path_c_str));
    #else
      GetModuleFileName(nullptr, path_c_str, sizeof(path_c_str) - 1);
      PathRemoveFileSpec(path_c_str);
    #endif
  #elif defined (__linux) || defined (__APPLE__)
    getcwd(path_c_str, sizeof(path_c_str) - 1);
  #endif
  std::string path(path_c_str);
  #ifdef _WIN32
    path += "\\v_rep.dll";
  #elif defined (__linux)
    path += "/libv_rep.so";
  #elif defined (__APPLE__)
    path += "/libv_rep.dylib";
  #endif /* __linux || __APPLE__ */
  return path;
}

}  // namespace

VREP_DLLEXPORT unsigned char v_repStart(void *reserved_ptr, int reserved_int) {
  vrep_lib = loadVrepLibrary(VrepLibPath().c_str());
  if (vrep_lib == nullptr) {
    PrintError("Failed to start: Could not find find or correctly load v_rep lib");
    return 0;
  }
  if (getVrepProcAddresses(vrep_lib) == 0) {
    PrintError("Failed to start: Could not find all required functions in v_rep lib");
    unloadVrepLibrary(vrep_lib);
    return 0;
  }
  int vrep_version;
  simGetIntegerParameter(sim_intparam_program_version, &vrep_version);
  if (vrep_version < kMinVrepVersion) {
    PrintError("Failed to start: VREP version too old (3.2.0 or higher is required)");
    unloadVrepLibrary(vrep_lib);
    return 0;
  }
  mavlink_server = std::make_unique<MavlinkServer>(14560);
  mavlink_server->start();
  // TODO(kgreenek): Import the version that is returned here from cmake config.
  return 1;
}

VREP_DLLEXPORT void v_repEnd() {
  assert(mavlink_server);
  mavlink_server->stop();
  unloadVrepLibrary(vrep_lib);
}

VREP_DLLEXPORT void *v_repMessage(int message, int *auxiliary_data, void *custom_data,
                                  int *reply_data) {
  // Stash error mode.
  int stashed_error_mode;
  simGetIntegerParameter(sim_intparam_error_report_mode, &stashed_error_mode);
  simSetIntegerParameter(sim_intparam_error_report_mode, sim_api_errormessage_ignore);
  void *result = nullptr;
  if (message == sim_message_eventcallback_modulehandle) {
    if ((custom_data == nullptr) || (kPluginName.compare(static_cast<char *>(custom_data)) == 0)) {
      PrintInfo("Received message: " + std::to_string(message));
    }
  }
  // Restore error mode.
  simSetIntegerParameter(sim_intparam_error_report_mode, stashed_error_mode);
  return result;
}
