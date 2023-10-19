 
rem  This make.bat must be in the same directory as the Visual Studio project files, 
rem  or else the error messages will not have the correct directory name preceeding 
rem  the file name, and clicking on the error messages will not work. 

::@echo off
::prompt $g$s

..\..\bin\lrstar LRK k=100 st d gh
..\..\bin\dfa    LRK d 
								  