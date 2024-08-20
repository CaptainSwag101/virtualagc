@echo off >NUL
:: This Windows batch script compiles a HAL/S program using the HAL/S-FC program,
:: which is assumed to be in the PATH.  
setlocal enabledelayedexpansion

set HALS_FILE=%~1
set TEST=%~2
set PARM_STRING=%~3
set TARGET=%~4
:: No parameter 5

set PYTHONUTF8=1

set FILES_PORTED="FILE1.bin FILE2.bin FILE3.bin FILE4.bin FILE5.bin FILE6.bin"
set FILES_PORTED="%FILES_PORTED:"=% &&TEMPLIB.json &&TEMPINC.json SOURCECO.txt"
set FILES_PORTED="%FILES_PORTED:"=% LIT_CHAR.bin SYM_TAB.json LISTING2.txt"
set FILES_PORTED="%FILES_PORTED:"=% CROSS_REF.json TEMPLIB.json"
set FILES_LOCAL="listing2.txt TEMPLIB TEMPLIBB cards.bin COMMON0.out halmat.bin"
set FILES_LOCAL="%FILES_LOCAL:"=% litfile.bin vmem.bin COMMON1.out COMMON2.out"
set FILES_LOCAL="%FILES_LOCAL:"=% COMMON3.out COMMON4.out auxmat.bin objcode.bin"
set FILES_LOCAL="%FILES_LOCAL:"=% optmat.bin pass1.rpt pass1p.rpt pass1A.rpt"
set FILES_LOCAL="%FILES_LOCAL:"=% pass1pA.rpt flo.rpt opt.rpt aux.rpt pass2.rpt"
set FILES_LOCAL="%FILES_LOCAL:"=% pass3.rpt pass4.rpt cards monitor13.parms"
set FILES_LOCAL="%FILES_LOCAL:"=% auxp.rpt deck.bin extra.txt"
del %FILES_PORTED% %FILES_LOCAL% >NUL 2>NUL

if not exist "%HALS_FILE%" (
        echo.
        echo. This script compiles a HAL/S file to an AP-101S object-code file.
        echo.
        echo.      HALSFC SOURCE.hal [ TEST [ "PARMS" [ TARGET ]]]
        echo.
        echo. Parameters appear in the indicated order.  Missing parameters
        echo. in the middle of the list can use \"\" as place markers for the.
        echo. defaults.  The parameters are interpreted as follows:
        echo.
        echo.      SOURCE.hal   The HAL/S source-code file.
        echo.      TEST         Perform all available validity tests.
        echo.      "PARMS"      Quoted list of comma-separated compiler options.
        echo.      TARGET       Use either PFS, the default, or BFS.
        echo.
        exit /B 1
)

set PARM_LIST=
if not "%PARM_STRING%." == "." set PARM_LIST=%PARM_STRING:,= %
::echo PARM_LIST = %PARM_LIST%

if "%TARGET%". == "BFS". (
    set PASS1=HALSFC-PASS1B
    set FLO=HALSFC-FLO
    set OPT=HALSFC-OPTB
    set AUXP=HALSFC-AUXP
    set PASS2=HALSFC-PASS2B
    set PASS3=HALSFC-PASS3B
    set PASS4=HALSFC-PASS4
    set TEMPLIB=TEMPLIBB
    set CARDS=--pdso=3,cards,E
) else (
    set PASS1=HALSFC-PASS1
    set FLO=HALSFC-FLO
    set OPT=HALSFC-OPT
    set AUXP=HALSFC-AUXP
    set PASS2=HALSFC-PASS2
    set PASS3=HALSFC-PASS3
    set PASS4=HALSFC-PASS4
    set TEMPLIB=TEMPLIB
    set CARDS=--ddo=3,cards.bin,E
)

%PASS1% ^
        --parm="%PARM_STRING%" ^
        --ddi=0,"%HALS_FILE%" ^
        --ddo=2,listing2.txt ^
        --pdsi=4,%TEMPLIB%,E ^
        --pdsi=5,ERRORLIB ^
        --pdsi=6,ACCESS  ^
        --pdso=6,%TEMPLIB%,E ^
        --commono=COMMON0.out ^
        --raf=B,7200,1,halmat.bin ^
        --raf=B,1560,2,litfile.bin ^
        --raf=B,3360,6,vmem.bin ^
        >pass1.rpt
if errorlevel 1 ( echo Aborted after PASS1 & exit /b 1 )

set IGNORE_LINES=(HAL/S^|FREE STRING AREA^|NUMBER OF FILE 6^|PROCESSING RATE^|CPU TIME FOR^|TODAY IS^|COMPOOL.*VERSION)
::echo IGNORE_LINES=%IGNORE_LINES%
if %TEST%x == TESTx (
echo ======================================================
for /f "tokens=*" %%i in ('where HAL_S_FC.py') do set HAL_S_FC=%%i
for /f "delims=" %%i in ("%HAL_S_FC%") do set ported=%%~dpi
( egrep -V >NUL 2>NUL && diff -v >NUL 2>NUL ) && echo Utilities egrep/diff available || exit /b 1
python "%HAL_S_FC%" %PARM_LIST% --hal="%HALS_FILE%" >pass1p.rpt && echo PASS1 cross-comparison test ... || exit /b 1
for %%i in ( %FILES_PORTED:"=% ) do copy %ported%..\%%i . >NUL 2>NUL
egrep -v "%IGNORE_LINES%" pass1.rpt  >pass1A.rpt
egrep -v "%IGNORE_LINES%" pass1p.rpt >pass1pA.rpt
diff --strip-trailing-cr -q -s pass1A.rpt pass1pA.rpt
diff --strip-trailing-cr -s FILE1.bin halmat.bin
if not "%PARM_LIST%" == "%PARM_LIST:LISTING2=%" diff -q -s LISTING2.txt listing2.txt
echo ======================================================
)

%FLO% ^
        --commoni=COMMON0.out ^
        --commono=COMMON1.out ^
        --raf=B,7200,1,halmat.bin ^
        --raf=B,1560,2,litfile.bin ^
        --raf=B,3360,6,vmem.bin ^
        >flo.rpt
if errorlevel 1 ( echo Aborted after FLO & exit /b 1 )


%OPT% ^
        --commoni=COMMON1.out ^
        --commono=COMMON2.out ^
        --raf=B,7200,1,halmat.bin ^
        --raf=B,1560,2,litfile.bin ^
        --raf=B,7200,4,optmat.bin ^
        --raf=B,3360,6,vmem.bin ^
        >opt.rpt
if errorlevel 1 ( echo Aborted after OPT & exit /b 1 )

%AUXP% ^
        --commoni=COMMON2.out ^
        --commono=COMMON3.out ^
        --raf=B,7200,1,auxmat.bin ^
        --raf=B,1560,2,litfile.bin ^
        --raf=B,7200,4,optmat.bin ^
        --raf=B,3360,6,vmem.bin ^
        >auxp.rpt
if errorlevel 1 ( echo Aborted after AUXP & exit /b 1 )


%PASS2% ^
        %CARDS% ^
        --ddo=4,deck.bin,E ^
        --pdsi=5,ERRORLIB ^
        --ddo=7,extra.txt ^
        --commoni=COMMON3.out ^
        --commono=COMMON4.out ^
        --raf=B,7200,1,auxmat.bin ^
        --raf=B,1560,2,litfile.bin ^
        --raf=B,1600,3,objcode.bin ^
        --raf=B,7200,4,optmat.bin ^
        --raf=B,3360,6,vmem.bin ^
        >pass2.rpt
if errorlevel 1 ( echo Aborted after PASS2 & exit /b 1 )

:: PASS3 and PASS4 aren't ready for use yet.

results=results
mkdir %results% >NUL 2>NUL
for %%i in ( %FILES_PORTED:"=% %FILES_LOCAL:"=% ) do move %%i %results% >NUL 2>NUL
copy "%HALS_FILE%" %results% >NUL 2>NUL

echo Compilation successful!
