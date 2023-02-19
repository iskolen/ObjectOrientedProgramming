@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

::�������� ������� �����
%PROGRAM% Empty.txt 1 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% Empty-out.txt
if ERRORLEVEL 1 goto err

::���������� ����
%PROGRAM% PositiveTest.txt asd > %OUT%
if ERRORLEVEL 1 goto err
fc %OUT% PositiveTest-out.txt
if ERRORLEVEL 1 goto err

::���� ������ ������, ����������� ������ �� ����� ������
%PROGRAM% TwoSearchStringInOne.txt asd > %OUT%
if ERRORLEVEL 1 goto err
fc %OUT% TwoSearchStringInOne-out.txt
if ERRORLEVEL 1 goto err

::���� �� ������� ��� �����
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoFileName-out.txt
if ERRORLEVEL 1 goto err

::���� �� ������� ������ ������
%PROGRAM% NoSearchString.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoSearchString-out.txt
if ERRORLEVEL 1 goto err

::�������� �� ������������� �����
%PROGRAM% asd.txt asd > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoFileExists-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1