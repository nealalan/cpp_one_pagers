@echo off
if "%3" == "" goto syntax
set progname=%1
set destination=%2
:top
shift
shift
echo ********************************************************** > %destination%
echo                      John Doe                              >> %destination%
echo                      Data File:  %1                        >> %destination%
echo ********************************************************** >> %destination%
echo. >> %destination%
echo. >> %destination%
%progname% < %1 >> %destination%
echo  >> %destination%
if not "%2" == "" goto top
goto finish
:syntax
echo Usage:   %0   program-name   destination  1st-data-file  [2nd-data-file ...]
echo.
echo For example:  %0  5e  prn  5e.1  5e.2  5e.3
:finish
echo.
