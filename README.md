## Project description and aim


## Project structure and organisation


#### The cmake way 
    
The commands to build the project would be:
``` 
    mkdir build_dir
    cd build_dir
    git clone https://github.com/craig-warner/CppBase.git 
    mkdir .vscode
    cp CppBase/Vcs/launch.json .vscode
    cmake ../CppBase 
    make 
```
Installation goes to /usr/local/ by default.
  
#### More advanced way 

To use it run `ccmake ..` in the top
directory of the project. Then turn on the options that you want by
going up and down with arrows, hitting "enter" to edit values and hitting
it again to exit edition. 
For example, you might want to enable building documentation for the
sample project. Then press "c" followed by "g" to generate a
makefile. It will bring you back to the terminal. Then type "make"
    
One can also pass parameters to cmake when configuring it using "-DMY_VARIABLE VALUE".
For example to build a debug version or a release version with debug symbols could look like : 
```
    cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
    cmake -DCMAKE_BUILD_TYPE=Debug ../CppBase
```
### Issues
    make install - does not work; may need sudo

#### List of targets 

From the ./build or ./ProjX/build, one can call :
* make [-j<number_of_parallel_jobs>]
* make test
* make install
* make doc
* make package

Important note : to be able to compile ProjB alone, one must first make and install ProjA. 
Moreover, one must add to PATH and LD_LIBRARY_PATH the installation directory of ProjA.

## Docs (Doxygen)

There is a default doc target in the CMakeLists.txt, which is built
when you type "make doc". You must have doxygen
installed on your system for this to work. See source code
for hints on how to write doxygen comments.
You can customize the output by editing config files in the doc directory.

Documentation is placed in: BUILD_DIR/doc BUILD_DIR is the build in which you say "make".
After installation, it will go by default to /usr/local/share.

## Tests

There are 2 dummy tests defined in the CMakeLists.txt. The unit test
source is in the test directory.  To run the dummy test, do "make
test".

## Boost

We include boost in the CMakeLists.txt using find_package(Boost ...) and 
passing a list of components we intend to use, namely unit_test_framework 
and program_options. 
    
The former is to ease the development of unit tests and the latter is 
to help getting options for your binaries. See apps/hellorunner/main.cxx 
for an example. 
    
## SVN and Git

The project shows how to use Git or SVN revision number. In the main 
CMakeLists.txt we include one or the other by commenting and uncommenting
the corresponding lines. It will define a CMake variable
that will be used when generating libs/hello/Version.h.

GetGitRevisionDescription module has been added to the CMake folder in the 
"CMake" directory in order to retrieve branch and revision information
from Git repository. Starting with Git 1.9 the module will be part of 
official cMake distribution, until then it has to be part of the 
application.
    
## Packaging

CPack permits building packages based on CMake. One should add CPackConfig
as it is done in the last line of the CMakeLists.txt. CPackConfig.cmake 
is in cmake folder and contains the required variables.
If you do "make package" it will create a tarball, a .deb and an rpm. 

## Code formatting and beautifier

The file .clang-formatter contains a set of rules that one can use to adapt
the source code to coding conventions. Clang has a number of predefined
formatting rules but here we use a custom one. To use it one must first 
install clang. 
To run it on a single file and see the modified file content : 
    
    clang-format -style=file <source file> # from the top directory

To run it on all subdirectories and replace the content of the .cxx and .h
files with the modified content : 

    find . -name *.cxx -o -name *.h | xargs clang-format -style=file -i
    

## Remarks

CMake is cross-platforms. Thus there are commands that might be there 
only to be compatible with one or the other platforms. In this project
we focus on Linux and removed most of these specificities for sake 
of simplicity.
    

For any question, please contact:
Barthélémy von Haller (barthelemy_vonhaller@yahoo.fr)

## VS Code Setup 

See Vsc/launch.json
This file should be copied to .vscode directory  