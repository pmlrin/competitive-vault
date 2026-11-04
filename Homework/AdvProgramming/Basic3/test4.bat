@echo off
echo Testing Staff
echo 1 > test_input.txt
echo 张三 >> test_input.txt
echo 5000 >> test_input.txt
echo 500 >> test_input.txt
echo 0.9 >> test_input.txt
echo n >> test_input.txt
type test_input.txt | 4.exe
echo.
echo Testing Saleman
echo 2 > test_input.txt
echo 李四 >> test_input.txt
echo 4000 >> test_input.txt
echo 400 >> test_input.txt
echo 0.8 >> test_input.txt
echo 0.05 >> test_input.txt
echo 10000 >> test_input.txt
echo n >> test_input.txt
type test_input.txt | 4.exe
echo.
echo Testing Manager
echo 3 > test_input.txt
echo 王五 >> test_input.txt
echo 6000 >> test_input.txt
echo 600 >> test_input.txt
echo 0.95 >> test_input.txt
echo 0.1 >> test_input.txt
echo 50000 >> test_input.txt
echo n >> test_input.txt
type test_input.txt | 4.exe
echo.
echo Testing SaleManager
echo 4 > test_input.txt
echo 赵六 >> test_input.txt
echo 7000 >> test_input.txt
echo 700 >> test_input.txt
echo 0.85 >> test_input.txt
echo 0.06 >> test_input.txt
echo 15000 >> test_input.txt
echo 0.12 >> test_input.txt
echo 60000 >> test_input.txt
echo n >> test_input.txt
type test_input.txt | 4.exe
del test_input.txt