@echo off

set DIR=%~dp0
call %DIR%batch_vars.bat
call "%BUILD%" DanMendozaGAME2342Editor Win64 Development "%DIR%DanMendozaGAME2342.uproject" -waitmutex -NoHotReload
