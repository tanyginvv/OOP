@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

echo good test1
set CORRECT1="correct1.txt"
%PROGRAM% 253 > %OUT% || goto err
fc %OUT% %CORRECT1% || goto err

echo good test2
set CORRECT2="correct2.txt"
%PROGRAM% 16 > %OUT% || goto err
fc %OUT% %CORRECT2% || goto err

echo good test3
set CORRECT3="correct3.txt"
%PROGRAM% 0 > %OUT% || goto err
fc %OUT% %CORRECT3% || goto err

echo input string
set INCORRECT1="incorrect1.txt"
%PROGRAM%  abc > %OUT%
fc %OUT% %INCORRECT1% && goto err

echo incorect arguements
set INCORRECT2="incorrect2.txt"
%PROGRAM%  15 56 > %OUT%
fc %OUT% %INCORRECT2% && goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1