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

> `g++ hello.cpp` 
- produces `a.out` executable file (macOS/Linux stop here)
- MinGW or MSYS2 versions of g++ (and most Windows builds of GCC) automatically add the .exe extension to executables, so you have `a.exe` file

> `g++ -S hello.cpp`
- `-S` produces only the compiled file_name and not assembling or linking. It will generate a `file_name.s` file in assembly

> `g++ -c hello.cpp`
- `-c` flag only compile and assemble the file_name 
- does not link the object code to produce executable file. It will generate a machine code file `file_name.o`

> `g++ -o target_name file_name file_name2`
- Compiles and links multiple files and generates executable target file with target_name (or a.out by default).

> `g++ -Wall file_name`
- prints all warning messages that are generated during compilation of file_name