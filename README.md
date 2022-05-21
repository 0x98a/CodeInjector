# Code Injector
A python program code injector

## Overview
A python code injector written in C++ using CPython - enjoy

## Features
It may be used to get code out raw through PyArmor (even the newest one) by dumping functions and replacing modules using custom injected code.
Supports python 3.7 - 3.10.4 (and 3.6 but not tested)

## How to use
Make a file named executecode in the same directory as the compiled DLL, and put your code in the file. Then inject the dll and it would run if the code is correct

Example code: print("i printed this") - this would print 'i printed this' inside the window if its a console window.
