#!/bin/sh

set -ex

case "$os" in
  linux32)
    # Prepare an i386 chroot. This is required as we otherwise can't install
    # our dependencies to be able to compile a 32bit binary. Ubuntu...
    chroot="$PWD"/buildroot.i386
    mkdir -p "$chroot$PWD"
    sudo apt-get install -y debootstrap
    sudo i386 debootstrap --arch=i386 precise "$chroot"
    sudo mount --rbind "$PWD" "$chroot$PWD"
    sudo i386 chroot "$chroot" add-apt-repository -y ppa:zoogie/sdl2-snapshots
    sudo i386 chroot "$chroot" add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo i386 chroot "$chroot" apt-get update -qq
    sudo i386 chroot "$chroot" apt-get install -qq libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev g++-4.8
    sudo i386 chroot "$chroot" export CXX="g++-4.8"

    ;;
  linux64)
    sudo add-apt-repository -y ppa:zoogie/sdl2-snapshots
    sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
    sudo apt-get update -qq
    sudo apt-get install -qq libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev g++-4.8
    export CXX="g++-4.8"
    ;;
esac
