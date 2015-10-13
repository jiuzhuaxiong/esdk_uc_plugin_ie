@echo off


echo.
echo －－－－－ 编译 IE Plugin －－－－－－－－－
@"%VS90COMNTOOLS%\..\IDE\devenv.com" ..\IECTDCTRL.sln /Clean "Release"
@"%VS90COMNTOOLS%\..\IDE\devenv.com" ..\IECTDCTRL.sln /Build "Release"
echo.
echo －－－－－ 编译 IE Plugin版本成功 －－－－－－－－

echo. 
echo －－－－－ 拷贝安装文件 －－－－－－－－－－
	::获得当前时间，作为生成版本的目录名
	for /F "tokens=1-4 delims=-/ " %%i in ('date /t') do (
	   set Year=%%i
	   set Month=%%j
	   set Day=%%k
	   set DayOfWeek=%%l
	)
	for /F "tokens=1-2 delims=: " %%i in ('time /t') do (
	   set Hour=%%i
	   set Minute=%%j
	)

	::设置各变量名
	set   	DateTime=%Year%-%Month%-%Day%

	rd /Q /S .\%DateTime%
	mkdir .\%DateTime%

	mkdir .\%DateTime%

	xcopy /Y /i /r /s ..\IECTDCTRL\Release\IECTDCTRL.dll .\%DateTime%
	xcopy /Y /i /r /s ..\install\* .\%DateTime%
	
pause