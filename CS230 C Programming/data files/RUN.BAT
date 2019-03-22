@echo off
if "%2" == "" goto syntax
set progname=%1
:top
shift
echo ********************************************************** > prn
echo                      John Doe                              > prn
echo                      Data File:  %1                        > prn
echo ********************************************************** > prn
echo. > prn
echo. > prn
%progname% < %1 > prn
echo  > prn
if not "%2" == "" goto top
goto finish
:syntax
echo Usage:   %0   program-name   1st-data-file  [2nd-data-file ...]
echo.
echo For example:  %0  5e  5e.1  5e.2  5e.3
:finish
echo.
