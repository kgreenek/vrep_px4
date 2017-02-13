#include "plugin.h"

VREP_DLLEXPORT unsigned char v_repStart(void *reserved_ptr, int reserved_int) {
  // TODO(kgreenek): Implement this.
  return 0;
}

VREP_DLLEXPORT void v_repEnd() {
  // TODO(kgreenek): Implement this.
}

VREP_DLLEXPORT void *v_repMessage(int message, int *auxiliary_data, void *custom_data,
                                  int *reply_data) {
  // TODO(kgreenek): Implement this.
}
