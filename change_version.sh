#!/bin/bash

# Get version in argument
if (($# != 1)); then
    echo -e "\033[31mUsage : $0 <new version>\033[0m"
    exit 1
fi
version=$1
major=$(echo "$version" | cut -d. -f1)
minor=$(echo "$version" | cut -d. -f2)
patch=$(echo "$version" | cut -d. -f3)

# Check that command http is installed
if ! type "http" >/dev/null; then
    echo -e "\033[31mhttp command not found. Please install it.\033[0m"
    exit 1
fi

echo -e "\033[34mChange version to \033[1m$version\033[0m"

# Download badge for version
echo -e " -> Download badge"
http --download --output=version.svg "https://img.shields.io/badge/version-$version-green" -q
echo -e "    \033[32mDone\033[0m"

# Change version in src/VERSION.h
# define FILC_VERSION_MAJOR $major
# define FILC_VERSION_MINOR $minor
# define FILC_VERSION_PATCH $patch
echo -e " -> Change version in src/VERSION.h"
sed -i "s/define FILC_VERSION_MAJOR .*/define FILC_VERSION_MAJOR $major/" src/VERSION.h
sed -i "s/define FILC_VERSION_MINOR .*/define FILC_VERSION_MINOR $minor/" src/VERSION.h
sed -i "s/define FILC_VERSION_PATCH .*/define FILC_VERSION_PATCH $patch/" src/VERSION.h
echo -e "    \033[32mDone\033[0m"
