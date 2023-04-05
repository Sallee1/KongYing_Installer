@echo off
setlocal enableextensions
set "folder=%~dp0"
timeout /t 10
cd /d "%SystemDrive%\"
rd /s /q "%folder%"
del %0