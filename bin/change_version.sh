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

# Change version in src/lib/utils/VERSION.h
# constexpr unsigned int FILC_VERSION_MAJOR = $major;
# constexpr unsigned int FILC_VERSION_MINOR = $minor;
# constexpr unsigned int FILC_VERSION_PATCH = $patch;
echo -e " -> Change version in src/lib/utils/VERSION.h"
sed -i "s/constexpr unsigned int FILC_VERSION_MAJOR = .*;/constexpr unsigned int FILC_VERSION_MAJOR = $major;/" src/lib/utils/VERSION.h
sed -i "s/constexpr unsigned int FILC_VERSION_MINOR = .*;/constexpr unsigned int FILC_VERSION_MINOR = $minor;/" src/lib/utils/VERSION.h
sed -i "s/constexpr unsigned int FILC_VERSION_PATCH = .*;/constexpr unsigned int FILC_VERSION_PATCH = $patch;/" src/lib/utils/VERSION.h
echo -e "    \033[32mDone\033[0m"
