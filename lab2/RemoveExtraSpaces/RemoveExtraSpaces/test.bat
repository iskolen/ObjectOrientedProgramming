@echo off

set PROGRAM="%~1"

set OUT="%TEMP%\out.txt"

:: Тест с -5 10 23 40 -24
%PROGRAM% <test1.txt> %OUT% || goto err
fc %OUT% test1-out.txt || goto err

:: Тест с -2 
%PROGRAM% <test2.txt> %OUT% || goto err
fc %OUT% test2-out.txt || goto err

:: Тест с 2
%PROGRAM% <test3.txt> %OUT% || goto err
fc %OUT% test3-out.txt || goto err

:: Тест с пустыми входными значениями
%PROGRAM% <test4.txt> %OUT% || goto err
fc %OUT% test4-out.txt || goto err


echo All tests passed
exit /B 0
	
:err
echo Program testing failed
exit /B 1