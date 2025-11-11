## Compiler
- compilation of code = converting source code to machine code unique to machine

C++ compiler goes through each `.cpp` file and does:
1. checks syntax - will error at this step if fails
2. translates into machine code
   - intermediate files are stored as "object file" with `.o` filetypes

## Linker
- Linker is a program that executes after compilation.

Linker purpose:
- combine all the `.o` object files and produce final executable to run

Linker will read through each `.o` object file and:
1. checks that `.o` file is valid
2. resolves all cross-file dependencies
3. "links" in the library files
4. outputs desired executable file

## Libraries
- C++ has a standardized library called **"C++ Standard Library"**

## Installation and Use in Windows Machines
1. Install IDE: VSCode
2. Install C/C++ extension in VSCode
3. Install MSYS2 
4. Install MinGW-w64 via MSYS2. MinGW toolkit = has all headers and libraries to run C++ on machine
    `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain`
5. Add environment variables to point to compiler (which is MinGW-w64 bin folder)
6. check MinGW installation
```
gcc --version
g++ --version
gdb --version
```


## Process of Compilation of program



