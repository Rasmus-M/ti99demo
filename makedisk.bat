@echo off

rem Assemble
python tools\xdt99\xas99.py -i -R -L controller.lst -o .\src\bin\demo0 .\src\controller\controller.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo1 .\src\effects\mstexas\mstexas.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo2 .\src\effects\mstexas\mstexas-tiap-pack.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo3 .\src\effects\dotfx\dotfx.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo4 .\src\effects\music\songbank3.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo5 .\src\effects\music\songbank1.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo6 .\src\effects\raycaster\raycaster.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo7 .\src\effects\raycaster\casterdata.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo8 .\src\effects\music\songbank4.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo9 .\src\effects\metaballs\metaballs.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo10 .\src\effects\ball\ball_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo11 .\src\effects\ball\ball-mask-shadow_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo12 .\src\effects\twist2\twist_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo13 .\src\effects\empty\empty.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo14 .\src\effects\multiplane\multiplane.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo15 .\src\effects\2dscroller\2dscroller_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo16 .\src\effects\checkerboard\chkbrd_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo17 .\src\effects\infinite-bobs\infinite-bobs_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo18 .\src\effects\splitscreen3\splitscreen3_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo19 .\src\effects\splitscreen2\splitscreen2_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo20 .\src\effects\splitscreen2\coltabs_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo21 .\src\effects\multicolor-rotozoom\multirotate_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo22 .\src\effects\infinite-dots\infinite-dots_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo23 .\src\effects\multisplit\multisplit_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo24 .\src\effects\multisplit\mode1map_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo25 .\src\effects\decoder\decoder_demo.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo26 .\src\effects\decoder\animation32.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo27 .\src\effects\decoder\animation33.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo28 .\src\effects\title\title.a99
tools\packcreds.exe .\src\effects\credits\credits.a99 .\src\effects\credits\credpacked.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo29 .\src\effects\credits\credpacked.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo30 .\src\effects\music\songbank2.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo31 .\src\effects\stretch\stretch.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo32 .\src\effects\stretch\data_bfe0.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo33 .\src\effects\stretch\data_dfc0.a99
python tools\xdt99\xas99.py -b -R -o .\src\bin\demo34 .\src\effects\splash\finalsplash.a99

rem Create disk
rem The order these appear in this list determines the bank index, so always add
rem to the end of the list!
if exist demo-dsdd.dsk (del demo-dsdd.dsk)

rem For now we're using a 360K image until we have reclaimed some more space
python tools\xdt99\xdm99.py demo-dsdd.dsk --initialize DSDD -n DEMO
rem python tools\xdt99\xdm99.py demo.dsk --initialize 720 -n DEMO

python tools\xdt99\xdm99.py demo-dsdd.dsk -a ^
    .\src\bin\demo0 ^
    .\src\bin\demo1_0000 ^
    .\src\bin\demo2_0000 ^
    .\src\bin\demo3_0000 ^
    .\src\bin\demo4_0000 ^
    .\src\bin\demo5_0000 ^
    .\src\bin\demo6_0000 ^
    .\src\bin\demo7_0000 ^
    .\src\bin\demo8_0000 ^
    .\src\bin\demo9_0000 ^
    .\src\bin\demo10_0000 ^
    .\src\bin\demo11_0000 ^
    .\src\bin\demo12_0000 ^
    .\src\bin\demo13_0000 ^
    .\src\bin\demo14_0000 ^
    .\src\bin\demo15_0000 ^
    .\src\bin\demo16_0000 ^
    .\src\bin\demo17_0000 ^
    .\src\bin\demo18_0000 ^
    .\src\bin\demo19_0000 ^
    .\src\bin\demo20_0000 ^
    .\src\bin\demo21_0000 ^
    .\src\bin\demo22_0000 ^
    .\src\bin\demo23_0000 ^
    .\src\bin\demo24_0000 ^
    .\src\bin\demo25_0000 ^
    .\src\bin\demo26_0000 ^
    .\src\bin\demo27_0000 ^
    .\src\bin\demo28_0000 ^
    .\src\bin\demo29_0000 ^
    .\src\bin\demo30_0000 ^
    .\src\bin\demo31_0000 ^
    .\src\bin\demo32_0000 ^
    .\src\bin\demo33_0000 ^
    .\src\bin\demo34_0000 ^
    -n DEMOA

call makesams.bat

python tools\xdt99\xdm99.py demo-dsdd.dsk -9 -a .\src\loader\LOAD