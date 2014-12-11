#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    sudo chroot ${PWD}/buildroot.i386 export CXX="g++-4.8"
    sudo chroot ${PWD}/buildroot.i386 make clean
    sudo chroot ${PWD}/buildroot.i386 make -j2
    ;;
  linux64)
    export CXX="g++-4.8"
    make clean
    make
    ;;
esac