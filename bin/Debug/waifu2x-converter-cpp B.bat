::waifu2x-converter-cpp
@echo off

waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 1 -m noise_scale -i "meidotai-n2-fix-n2-s.jpg" -o "meidotai-n2-fix-n2-s-n1s.jpg"
waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 1 -m scale -i "meidotai-n2-fix-n2-s.jpg" -o "meidotai-n2-fix-n2-s-s.jpg"
waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 1 -m scale -i "meidotai-n2-fix-n2-s-n1s.jpg" -o "meidotai-n2-fix-n2-s-n1s-s.jpg"
waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 1 -m scale -i "meidotai-n2-fix-n2-s-s.jpg" -o "meidotai-n2-fix-n2-s-s-s.jpg"
::waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 1 -m noise_scale -i "meidotai-n2-fix-n2-s-n1s-s.jpg" -o "meidotai-n2-fix-n2-s-n1s-s-n1s.jpg"
::waifu2x-converter-cpp.exe -j 4 --model_dir "models" --noise_level 1 -m noise_scale -i "meidotai-n2-fix-n2-s-s-s.jpg" -o "meidotai-n2-fix-n2-s-s-s-n1s.jpg"




pause
