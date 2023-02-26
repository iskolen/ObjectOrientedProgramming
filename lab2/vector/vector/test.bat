@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

echo "Empty value check"
%PROGRAM% # > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% EmptyVector-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1