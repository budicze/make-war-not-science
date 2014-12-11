#!/bin/sh

set -e
set -x

case "${os}" in
  linux32)
    sudo chroot ${PWD}/buildroot.i386 make clean
    sudo chroot ${PWD}/buildroot.i386 make -j2
    ;;
  linux64)
    make clean
    make
    ;;
esac