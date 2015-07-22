::waifu2x-converter-cpp
@echo off

:: 切换执行路径 因为调用方会导致工作目录改变 所以要切回本路径再调用exe

cd /d %~d0
cd %~dp0

title noise_scale 2 : %~n1%~x1
waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 2 -m noise_scale -i "%~d1%~p1%~n1%~x1" -o "%~d1%~p1%~n1-n2s.png"


