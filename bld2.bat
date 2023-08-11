REM FE2  Testplugin

REM --------------------------------------
REM  For Opencpn 5.8 and wxWidgets-3.2.2 using Visual Studio 15 2017
REM --------------------------------------
REM Used for local builds and testing.
REM Use bash prompt because of the cloudsmith-upload.sh at the end.
REM Set local environment using wxWidgets-3.2.2
REM set "wxDIR=%WXWIN%"
REM set "wxWidgets_ROOT_DIR=%WXWIN%"
REM set "wxWidgets_LIB_DIR=%WXWIN%\lib\vc14x_dll" 
REM set "WXWIN=C:\Users\fcgle\source\wxWidgets-3.2.2"
REM  For Opencpn 5.8 and wxWidgets-3.2.2
REM cd build
REM cmake -T v143 -A Win32 -DOCPN_TARGET=MSVC ..
REM cmake --build . --target package --config relwithdebinfo >output.txt
REM bash ./cloudsmith-upload.sh

REM --------------------------------------
REM  For Opencpn 5.6.2 and wxWidgets-3.1.2  release
REM --------------------------------------
REM  Using built C:\Users\fcgle\source\wxWidgets-3.1.2 and local settings
wxDIR=C:\Users\fcgle\source\wxWidgets-3.1.2
wxWidgets_Root_Dir=C:\Users\fcgle\source\wxWidgets-3.1.2\lib\vc14x_dll
wxWidgets_LIB_DIR=\lib\vc14x_dll
WXWIN=C:\Users\fcgle\source\wxWidgets-3.1.2
REM set "wxDIR=%WXWIN%"
REM set "wxWidgets_ROOT_DIR=%WXWIN%" 
REM set "wxWidgets_LIB_DIR=%WXWIN%\lib\vc14x_dll" 
REM set "WXWIN=C:\Users\fcgle\source\wxWidgets-3.1.2"
cd build
cmake -T v141_xp -DOCPN_TARGET=MSVC ..
cmake --build . --target package --config release >output.txt
REM bash ./cloudsmith-upload.sh




