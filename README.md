# vrep_px4

A plugin for the V-REP simulator that enables connecting a drone model in V-REP to PX4.

## Install dependencies

    sudo apt-get install cmake ninja-build git

## Build & Install Instructions

Download V-REP if you haven't already.

    # Replace this with the location of your VREP download.
    export VREP_DIR="~/VREP"
    git clone https://github.com/kgreenek/vrep_px4.git
    cd vrep_px4
    mkdir build && cd build
    cmake .. -G Ninja -DCMAKE_INSTALL_PREFIX="$VREP_DIR"
    ninja install

This will build the plugin and install it to your VREP dir so VREP can load it at startup. It also installs a new model in robots/mobile called "PX4 Quadrotor".
