::waifu2x-converter-cpp
@echo off

:: �л�ִ��·�� ��Ϊ���÷��ᵼ�¹���Ŀ¼�ı� ����Ҫ�лر�·���ٵ���exe

cd /d %~d0
cd %~dp0

title noise_scale 2 : %~n1%~x1
waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 2 -m noise_scale -i "%~d1%~p1%~n1%~x1" -o "%~d1%~p1%~n1-n2s.png"


