  
rem  This make.bat must be in the same directory as the Visual Studio project files, 
rem  or else the error messages will not have the correct directory name preceeding 
rem  the file name, and clicking on the error messages will not work. 

@echo off
prompt $g$s

..\..\bin\lrstar Java9 /k=30 /d /st	crr csr
..\..\bin\dfa Java9 /d /st	
