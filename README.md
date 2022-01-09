# Setup

Setting up libtcod to work with the following:

- VSCode
- MSYS2

## MSYS2 Setup

1. Install MSYS2 and follow normal install instructions, update packages with pacman.
2. In the MSYS2 MSYS console, run:

```
 pacman -S --needed git base-devel mingw-w64-x86_64-toolchain  mingw-w64-x86_64-clang mingw-w64-x86_64-cmake
```

3.  Close MSYS2 MSYS console, and now open MSYS2 MINGW 64-bit console
4. Type the following to confirm installation of compiler toolchain.

```
   g++ --version
   g++ -dumpmachine
   clang --version
   make --version
   cmake --version
```

## Install vcpkg in msys2 mingw64

---

From
https://github.com/microsoft/vcpkg/blob/master/docs/users/mingw.md

https://github.com/microsoft/vcpkg/blob/master/docs/users/integration.md

1. Open MSYS2 MinGW 64-bit variant of the console, or type: source shell mingw64
2.

```
  cd /mingw64/bin
  git clone https://github.com/microsoft/vcpkg.git
  cd vcpkg
  ./bootstrap-vcpkg.bat
  export VCPKG_DEFAULT_TRIPLET=x64-mingw-static
  export VCPKG_DEFAULT_HOST_TRIPLET=x64-mingw-static
```

To test setup

```
./vcpkg install zlib:x64-mingw-static
```

For the real deal

```
./vcpkg install libtcod:x64-mingw-static
```

# VSCode

---

1.  Install VSCode
2. Clone this repo somewhere (setup branch)

```
git clone -b setup https://github.com/raspberrypisig/roguelike-firststab
```

3.  Left click on Extensions on left sidebar, then search and install the C/C++ Extension Pack from Microsoft
4.  In the CMake toolbar at the bottom, select "No Kit Selected", then select ""Mingw64 GCC 11.2.0" (This comes from .vscode/cmake-kits.json)
5.  To build, click Build on the CMake toolbar at the bottom of the screen.
6.  To run, click the play button on the CMake toolbar at the bottom of the screen.
7.  To debug, click on the bug icon to the left of the play button.
