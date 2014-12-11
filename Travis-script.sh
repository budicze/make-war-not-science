#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    sudo chroot ${PWD}/buildroot.i386 make -C ${PWD} clean
    sudo chroot ${PWD}/buildroot.i386 make -C ${PWD} -j2 CXX="g++-4.8" 
    ;;
  linux64)
    export CXX="g++-4.8"
    make clean
    make
    ;;
esac