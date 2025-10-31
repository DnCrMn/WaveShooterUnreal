@echo off

set DIR=%~dp0
call %DIR%batch_vars.bat
call "%UBT%" -projectfiles -vscode -game -engine -dotnet -progress -noIntelliSense "%DIR%DanMendozaGAME2342.uproject"
ue-assist -c "%DIR%.vscode\compileCommands_DanMendozaGAME2342.json" "%DIR%compile_commands.json"