@echo off


echo.
echo ���������� ���� IE Plugin ������������������
@"%VS90COMNTOOLS%\..\IDE\devenv.com" ..\IECTDCTRL.sln /Clean "Release"
@"%VS90COMNTOOLS%\..\IDE\devenv.com" ..\IECTDCTRL.sln /Build "Release"
echo.
echo ���������� ���� IE Plugin�汾�ɹ� ����������������

echo. 
echo ���������� ������װ�ļ� ��������������������
	::��õ�ǰʱ�䣬��Ϊ���ɰ汾��Ŀ¼��
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

	::���ø�������
	set   	DateTime=%Year%-%Month%-%Day%

	rd /Q /S .\%DateTime%
	mkdir .\%DateTime%

	mkdir .\%DateTime%

	xcopy /Y /i /r /s ..\IECTDCTRL\Release\IECTDCTRL.dll .\%DateTime%
	xcopy /Y /i /r /s ..\install\* .\%DateTime%
	
pause