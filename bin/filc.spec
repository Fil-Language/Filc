Name: filc
Version: @@VERSION@@
Release: 1%{?dist}
Summary: Fil language compiler

License: MIT
Source0: %{name}-%{version}.tar.gz
URL: https://fil.ktraini.com

%description
A compiler for Fil language

%prep
%setup -q

%install
rm -rf "$RPM_BUILD_ROOT"
mkdir -p "$RPM_BUILD_ROOT/%{_bindir}"
cp %{name} "$RPM_BUILD_ROOT/%{_bindir}"

%files
%{_bindir}/%{name}
