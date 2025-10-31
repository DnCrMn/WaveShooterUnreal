@echo off

set DIR=%~dp0
call %DIR%batch_vars.bat
start "%UE5EDITOR%" "%DIR%DanMendozaGAME2342.uproject" %*