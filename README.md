Setup
------

Setting up libtcod to work with the following:

* VSCode
* MSYS2(MinGW64)


MSYS2 Setup
------------

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

 VSCode
 ---------
 1. Install VSCode
 2. Left click on Extensions on left sidebar, then search and install the C/C++ Extension Pack from Microsoft
 3. Press F1 to open the Command Palette, type:  settings json
    pick the option "Preferences: Open Workspace Settings(JSON)"
 4. Type the following in a Windows Command Prompt to verify installation:
 ```
    g++ --version
    g++ -dumpmachine
    make --version
    cmake --version
 ```
 
 5. In the CMake toolbar at the bottom, select
 "No Active Kit", then select [Scan for Kits]
 6. Press F1 to open the Command Palette: cmake edit
    pick "CMake: Edit User-Local CMake Kits"
 7. Append to the list with a comma, the fragment from cmake-tools-kits-fragment.json in this repo. Do not overwrite the entries all ready there.   
 8. Clicking on "No Active Kit" will now show an entry at the bottom "Mingw64 GCC 11.2.0"
 9. To build, click Build on the CMake toolbar at the bottom of the screen.
 10. To run, click the play button on the CMake toolbar at the bottom of the screen.
 
 install vcpkg in msys2 mingw64
 -------------------------------
 From 
 https://github.com/microsoft/vcpkg/blob/master/docs/users/mingw.md
 https://github.com/microsoft/vcpkg/blob/master/docs/users/integration.md
 
 1. Open MSYS2 MinGW 64-bit variant of the console, or type:  source shell mingw64
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
 