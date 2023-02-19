@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

::Проверка пустого файла
%PROGRAM% Empty.txt 1 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% Empty-out.txt
if ERRORLEVEL 1 goto err

::Позитивный тест
%PROGRAM% PositiveTest.txt asd > %OUT%
if ERRORLEVEL 1 goto err
fc %OUT% PositiveTest-out.txt
if ERRORLEVEL 1 goto err

::Если строка поиска, присутствут дважды на одной строке
%PROGRAM% TwoSearchStringInOne.txt asd > %OUT%
if ERRORLEVEL 1 goto err
fc %OUT% TwoSearchStringInOne-out.txt
if ERRORLEVEL 1 goto err

::Если не введено имя файла
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoFileName-out.txt
if ERRORLEVEL 1 goto err

::Если не введена строка поиска
%PROGRAM% NoSearchString.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoSearchString-out.txt
if ERRORLEVEL 1 goto err

::Проверка на существование файла
%PROGRAM% asd.txt asd > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% NoFileExists-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1