@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

echo "Checking the maximum value"
%PROGRAM% 4294967295 > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% MaxInt-out.txt
if ERRORLEVEL 1 goto err

echo "Checking the minimum value"
%PROGRAM% 0 > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% MinInt-out.txt
if ERRORLEVEL 1 goto err

echo "Checking for the absence of an input parameter"
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoParameter-out.txt
if ERRORLEVEL 1 goto err

echo "Checking a negative value"
%PROGRAM% -1 > %OUT%
if NOT ERRORLEVEL 2 goto err
fc %OUT% NegativeInt-out.txt
if ERRORLEVEL 1 goto err

echo "Checking the string"
%PROGRAM% asd > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% NoDigit-out.txt
if ERRORLEVEL 1 goto err

echo "Checking for exceeding the maximum value"
%PROGRAM% 4294967296 > %OUT%
if NOT ERRORLEVEL 4 goto err
fc %OUT% Exceed-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1