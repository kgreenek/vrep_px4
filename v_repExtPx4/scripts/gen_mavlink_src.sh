#!/bin/bash
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
MAVLINK_INSTALL_DIR="$DIR/../src/mavlink/"
TMP_DIR=$(mktemp -d)
echo "Creating tmp dir ${TMP_DIR}..."
cd $TMP_DIR
if ! git clone https://github.com/mavlink/mavlink ; then
  rm -rf $TMP_DIR
  echo "ERROR: Could not clone mavlink"
  exit 1
fi
PYTHONPATH=$PYTHONPATH:$TMP_DIR/mavlink
cd mavlink
if ! git submodule update --init --recursive ; then
  rm -rf $TMP_DIR
  echo "ERROR: Could not init mavlink submodules"
  exit 1
fi
mkdir build
cd build
echo "Configuring mavlink..."
if ! cmake .. -G Ninja ; then
  rm -rf $TMP_DIR
  echo "ERROR: cmake failed"
  exit 1
fi
echo "Building mavlink..."
if ! ninja ; then
  rm -rf $TMP_DIR
  echo "ERROR: ninja build failed"
  exit 1
fi
echo "Copying mavlink sources to ${MAVLINK_INSTALL_DIR}..."
rm -rf $MAVLINK_INSTALL_DIR
cp -rf include $MAVLINK_INSTALL_DIR
rm -rf $TMP_DIR
