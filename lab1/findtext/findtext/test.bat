@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

echo "Checking an empty file"
%PROGRAM% Empty.txt 1 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% Empty-out.txt
if ERRORLEVEL 1 goto err

echo "Search for the string 'asd' in the file where they are present"
%PROGRAM% PositiveTest.txt asd > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% PositiveTest-out.txt
if ERRORLEVEL 1 goto err

echo "If the search string is present twice on the same line"
%PROGRAM% TwoSearchStringInOne.txt asd > %OUT%
if NOT ERRORLEVEL 0 goto err
fc %OUT% TwoSearchStringInOne-out.txt
if ERRORLEVEL 1 goto err

echo "If no file name is entered"
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 2 goto err
fc %OUT% NoFileName-out.txt
if ERRORLEVEL 1 goto err

echo "If the search string is not entered"
%PROGRAM% NoSearchString.txt > %OUT%
if NOT ERRORLEVEL 3 goto err
fc %OUT% NoSearchString-out.txt
if ERRORLEVEL 1 goto err

echo "Checking for the existence of a file"
%PROGRAM% asd.txt asd > %OUT%
if NOT ERRORLEVEL 4 goto err
fc %OUT% NoFileExists-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1