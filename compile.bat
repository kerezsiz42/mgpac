@echo off
cd %~dp0
cls
clang++ -Wall -std=c++14 -target x86_64-pc-windows-gnu main.cpp -o mgpac.exe
start cmd /c mgpac.exe ^& pause