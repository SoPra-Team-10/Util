[![Build Status](https://travis-ci.org/SoPra-Team-10/Util.svg?branch=master)](https://travis-ci.org/SoPra-Team-10/Network)
# Utilities
Several utilities used in our C++ Codebase.

## Overview

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
