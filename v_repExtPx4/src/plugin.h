#ifndef V_REPEXTPX4_PLUGIN_H_
#define V_REPEXTPX4_PLUGIN_H_

#ifdef _WIN32
  #define VREP_DLLEXPORT extern "C" __declspec(dllexport)
#endif  // _WIN32
#if defined(__linux) || defined(__APPLE__)
  #define VREP_DLLEXPORT extern "C"
#endif  // __linux || __APPLE__

// The 3 required entry points of the V-REP plugin.
VREP_DLLEXPORT unsigned char v_repStart(void *reserved_ptr, int reserved_int);
VREP_DLLEXPORT void v_repEnd();
VREP_DLLEXPORT void *v_repMessage(int message, int *auxiliary_data, void *custom_data,
                                  int *reply_data);

#endif  // V_REPEXTPX4_PLUGIN_H_
