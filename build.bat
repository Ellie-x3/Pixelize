@echo off

if "%1"=="-clean" (
	msbuild Pixelize.sln /t:Clean;Build
) else (
	msbuild Pixelize.sln /t:Build
)