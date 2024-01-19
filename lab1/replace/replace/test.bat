@echo off
set PROGRAM="%~1"

echo something good test
set IN1="in1.txt"
set OUT1="out1.txt"
set CORRECT1="test_out1.txt"
%PROGRAM% %IN1% %OUT1% ma pa || goto err
fc %OUT1% %CORRECT1% || goto err

echo substring
set IN2="complex_substring.txt"
set OUT2="complex_substring_output.txt"
set CORRECT2="complex_substring_output_test-out.txt"
%PROGRAM% %IN2% %OUT2% 1231234 * || goto err
fc %OUT2% %CORRECT2% || goto err

echo invalid parametrs
set OUT4="invalid_parametrs_out.txt"
set CORRECT4="invalid_parametrs_out-test.txt"
%PROGRAM% exe exe %OUT4%  
fc %OUT4% %CORRECT4% || goto err

echo empty line
set IN5="empty_line.txt"
set OUT5="empty_line_output.txt"
set CORRECT5="empty_line_test-out.txt"
%PROGRAM% %IN5% %OUT5% "" warning || goto err
fc %OUT5% %CORRECT5% || goto err

echo big data
set IN6="big_data.txt"
set OUT6="big_data_out.txt"
set CORRECT6="big_data_test_out.txt"
%PROGRAM% %IN6% %OUT6% ma pa || goto err
fc %OUT6% %CORRECT6% || goto err


echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1