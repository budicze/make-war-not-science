#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    sudo chroot ${PWD}/buildroot.i386 make -C ${PWD} clean
    sudo chroot ${PWD}/buildroot.i386 make -C ${PWD} -j2 CXX="g++-4.8" 
    ;;
  linux64)
    make clean
    make -j2 CXX="g++-4.8"
    ;;
esac