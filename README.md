[![Build Status](https://travis-ci.org/SoPra-Team-10/Util.svg?branch=master)](https://travis-ci.org/SoPra-Team-10/Network)
# Utilities
Several utilities used in our C++ Codebase.

## Overview
### Timer
The timer class represents a simple single-shot timer with an interface 
similar to the `setTimeout()` function in javascript. Additionally it
supports pausing and resuming the timeout. There are two import things to
keep in mind: the function runs in a different thread than the caller,
this can lead to the usual multithreading issues. Secondly the class doesn't
support setting a new function while the timer is running, this will lead 
to an `std::runtime_error`.

### Logging
The logging library wraps around any `ostream` (for example `std::cout`
or `ofstream` (output-file-stream)) and provides filtering
depending on the log level and coloring depending on the log level.
Furthermore it prepends every message with the current timestamp.

## Installing
### Installing Utilities
In the root directory of the  project run cmake to generate a Makefile by running
```
cmake .
```
next compile the program by running
```
make
```
finally install the program by running
```
sudo make install
```
the library can now be included using

```
#include <SopraUtil/Filename>
```
with `Filename` beeing one of the header files without their relative path.

and linked using

```
-lSopraUtil
```
## SonarQube Analyse
Das Analyseergebniss von SonarQube ist [hier auf SonarCloud](https://sonarcloud.io/dashboard?id=SoPra-Team-10_Util) zu finden.
