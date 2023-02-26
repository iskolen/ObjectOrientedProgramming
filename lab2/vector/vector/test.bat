@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

echo "Empty value check"
%PROGRAM% < Empty.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% Empty-out.txt
if ERRORLEVEL 1 goto err

echo "Checking if the minimum value is 0"
%PROGRAM% < MinValueZero.txt > %OUT%
if NOT ERRORLEVEL 2 goto err
fc %OUT% MinValueZero-out.txt
if ERRORLEVEL 1 goto err

echo "Checking only positive numbers: [3 2 1]"
%PROGRAM% < PositiveNumbers.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% PositiveNumbers-out.txt
if ERRORLEVEL 1 goto err

echo "Checking positive and negative numbers: [-12 -3 13 7]"
%PROGRAM% < PositiveNegativeNumbers.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% PositiveNegativeNumbers-out.txt
if ERRORLEVEL 1 goto err

echo "Checking of real numbers: [-12.123 5.231 16 -90]"
%PROGRAM% < RealNumbers.txt > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% RealNumbers-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1