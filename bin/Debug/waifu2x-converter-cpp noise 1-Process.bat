::waifu2x-converter-cpp
@echo off

cd /d %~d0
cd %~dp0

title noise 1 : %~n1%~x1
waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 1 -m noise -i "%~d1%~p1%~n1%~x1" -o "%~d1%~p1%~n1-n1.png"


