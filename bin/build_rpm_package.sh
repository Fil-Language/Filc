#!/bin/bash

if (($# != 2)); then
  echo -e "\033[31mUsage : $0 <binary path> <version>\033[0m"
  exit 1
fi

binary_path=$1
version=$2

# Check that command rpm is installed
if ! type "rpmbuild" >/dev/null; then
  echo -e "\033[31mrpmbuild command not found. Please install it.\033[0m"
  exit 1
fi

# Create rpmbuild structure
mkdir -p ~/rpmbuild/BUILD
mkdir -p ~/rpmbuild/RPMS
mkdir -p ~/rpmbuild/SOURCES
mkdir -p ~/rpmbuild/SPECS
mkdir -p ~/rpmbuild/SRPMS

# Move binary into sources
source_dir_name="filc-$version"
mkdir "$source_dir_name"
cp "$binary_path" "$source_dir_name/"
tar --create --file "$source_dir_name.tar.gz" "$source_dir_name"
mv "$source_dir_name.tar.gz" ~/rpmbuild/SOURCES

# Move spec to specs
sed "s/@@VERSION@@/$version/g" bin/filc.spec >~/rpmbuild/SPECS/filc.spec

# Build rpm
rpmbuild -ba ~/rpmbuild/SPECS/filc.spec

# Display result
tree ~/rpmbuild/RPMS
