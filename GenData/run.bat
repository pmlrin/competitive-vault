@echo off
setlocal enabledelayedexpansion

for /l %%i in (1,1,50) do (
    :: echo Generating input for test ...
    :: in.exe > .in
    echo Running std.exe on %%i.in...
    std.exe < %%i.in > %%i.out
)

echo All tests completed.
pause