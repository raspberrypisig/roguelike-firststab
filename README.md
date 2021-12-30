## Setup

Setting up libtcod to work with the following:

- VSCode
- MSYS2(MinGW64)

## MSYS2 Setup

1. Install MSYS2
2. Follow normal install instructions, update packages with pacman etc.
3. Add the following directories to PATH :
   C:\msys64\mingw64\bin
4. Run the following commands in a MSYS2 (prefer the MSYS2 MinGW 64-bit variant)console:

```
 pacman -S --needed git base-devel mingw-w64-x86_64-toolchain  mingw-w64-x86_64-clang mingw-w64-x86_64-cmake
 cd /mingw64/bin
 ln -s mingw32-make.exe make.exe
```

5.  Type the following in a Windows Command Prompt to verify installation:

```
   g++ --version
   g++ -dumpmachine
   clang --version
   make --version
   cmake --version
```

install vcpkg in msys2 mingw64

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

VSCode

---

1.  Install VSCode
2.  git clone this repo and open in VSCode
3.  In this repo, have a look at the following files:
    - CMakeLists.txt
    - .vscode/c_cpp_properties.json
    - .vscode/cmake-kits.json
4.  Left click on Extensions on left sidebar, then search and install the C/C++ Extension Pack from Microsoft
5.  In the CMake toolbar at the bottom, select "No Active Kit", then select ""Mingw64 GCC 10.2.0" (This comes from .vscode/cmake-kits.json)
6.  To build, click Build on the CMake toolbar at the bottom of the screen.
7.  To run, click the play button on the CMake toolbar at the bottom of the screen.
8.  To debug, click on the bug icon to the left of the play button.
