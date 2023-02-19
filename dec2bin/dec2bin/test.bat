@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

::�������� ������������ ��������
%PROGRAM% 0 > %OUT%
if ERRORLEVEL 1 goto err
fc %OUT% ZeroInt-out.txt
if ERRORLEVEL 1 goto err

::�������� ������������� ��������
%PROGRAM% 4294967295 > %OUT%
if ERRORLEVEL 1 goto err
fc %OUT% MaxInt-out.txt
if ERRORLEVEL 1 goto err

::�������� �������� ��������
%PROGRAM% 253 > %OUT%
if ERRORLEVEL 1 goto err
fc %OUT% 253-out.txt
if ERRORLEVEL 1 goto err

::�������� ������
%PROGRAM% asd > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% String-out.txt
if ERRORLEVEL 1 goto err

::�������� �������������� ��������
%PROGRAM% -1 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NegativeInt-out.txt
if ERRORLEVEL 1 goto err

::�������� ���������� ������������� ��������
%PROGRAM% 4294967296 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% MaxIntExceed-out.txt
if ERRORLEVEL 1 goto err

::�������� �� ��������� �������� ���������
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoParameter-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1