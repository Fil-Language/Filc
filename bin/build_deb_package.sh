#!/bin/bash

if (($# != 3)); then
  echo -e "\033[31mUsage : $0 <binary path> <version> <architecture>\033[0m"
  exit 1
fi

binary_path=$1
version=$2
architecture=$3

mkdir -p filc/DEBIAN
mkdir -p filc/usr/bin
mkdir -p filc/usr/share/doc/filc

cp "$binary_path" filc/usr/bin
cp LICENSE.md filc/usr/share/doc/filc/copyright
cp CHANGELOG.md filc/usr/share/doc/filc/changelog

echo "
Package: filc
Version: $version
Section: devel
Priority: optional
Architecture: $architecture
Maintainer: Kevin Traini <kevin@ktraini.com>
Description: Fil language compiler
Homepage: https://fil.ktraini.com" >filc/DEBIAN/control

dpkg-deb --build filc
