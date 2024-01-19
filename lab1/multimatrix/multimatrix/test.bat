@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

set IN11="matrix11.txt"
set IN12="matrix12.txt"
set OUT1="out1.txt"
%PROGRAM% %IN11% %IN12% > %OUT% 
fc %OUT% %OUT1% || goto err

set IN21="matrix21.txt"
set IN22="matrix22.txt"
set OUT2="out2.txt"
%PROGRAM% %IN21% %IN22% > %OUT% 
fc %OUT% %OUT2% || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1