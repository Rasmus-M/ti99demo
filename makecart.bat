rem Assemble
python tools\xdt99\xas99.py -b -R -L controller.lst -D CARTRIDGE -o .\src\bin\demo0 --base 0x6000 .\src\controller\controller.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo1 --base 0x6000 .\src\effects\lena\lenap.a99 
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo2 --base 0x6000 .\src\effects\lena\lenac.a99 
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo3 --base 0x6000 .\src\effects\dotfx\dotfx.a99 
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo4 --base 0x6000 .\src\effects\lena\loadlena.a99 
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo5 --base 0x6000 .\src\effects\music\songbank1.a99 
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo6 --base 0x6000 .\src\effects\raycaster\raycaster.a99 
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo7 --base 0x6000 .\src\effects\raycaster\casterdata.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo8 --base 0x6000 .\src\effects\squaretunnel\squaretunnel.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo9 --base 0x6000 .\src\effects\metaballs\metaballs.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo10 --base 0x6000 .\src\effects\ball\ball_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo11 --base 0x6000 .\src\effects\ball\ball-mask-shadow_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo12 --base 0x6000 .\src\effects\twist2\twist_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo13 --base 0x6000 .\src\effects\twist2\twistmap_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo14 --base 0x6000 .\src\effects\multiplane\multiplane.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo15 --base 0x6000 .\src\effects\2dscroller\2dscroller_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo16 --base 0x6000 .\src\effects\checkerboard\chkbrd_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo17 --base 0x6000 .\src\effects\infinite-bobs\infinite-bobs_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo18 --base 0x6000 .\src\effects\splitscreen3\splitscreen3_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo19 --base 0x6000 .\src\effects\splitscreen2\splitscreen2_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo20 --base 0x6000 .\src\effects\splitscreen2\coltabs_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo21 --base 0x6000 .\src\effects\multicolor-rotozoom\multirotate_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo22 --base 0x6000 .\src\effects\infinite-dots\infinite-dots_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo23 --base 0x6000 .\src\effects\multisplit\multisplit_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo24 --base 0x6000 .\src\effects\multisplit\mode1map_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo25 --base 0x6000 .\src\effects\decoder\decoder_demo.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo26 --base 0x6000 .\src\effects\decoder\animation32.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo27 --base 0x6000 .\src\effects\decoder\animation33.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo28 --base 0x6000 .\src\effects\title\dontmessp.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo29 --base 0x6000 .\src\effects\title\dontmessc.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo30 --base 0x6000 .\src\effects\title\title.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo31 --base 0x6000 .\src\effects\credits\credits.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo32 --base 0x6000 .\src\effects\music\songbank2.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo33 --base 0x6000 .\src\effects\stretch\stretch.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo34 --base 0x6000 .\src\effects\stretch\data_bfe0.a99
python tools\xdt99\xas99.py -b -R -D CARTRIDGE -o .\src\bin\demo35 --base 0x6000 .\src\effects\stretch\data_dfc0.a99

rem Pad to 8192 bytes (size of 1 bank)
tools\pad .\src\bin\demo0_6000 .\src\bin\demo0.bin 8192
tools\pad .\src\bin\demo1_6000 .\src\bin\demo1.bin 8192
tools\pad .\src\bin\demo2_6000 .\src\bin\demo2.bin 8192
tools\pad .\src\bin\demo3_6000 .\src\bin\demo3.bin 8192
tools\pad .\src\bin\demo4_6000 .\src\bin\demo4.bin 8192
tools\pad .\src\bin\demo5_6000 .\src\bin\demo5.bin 8192
tools\pad .\src\bin\demo6_6000 .\src\bin\demo6.bin 8192
tools\pad .\src\bin\demo7_6000 .\src\bin\demo7.bin 8192
tools\pad .\src\bin\demo8_6000 .\src\bin\demo8.bin 8192
tools\pad .\src\bin\demo9_6000 .\src\bin\demo9.bin 8192
tools\pad .\src\bin\demo10_6000 .\src\bin\demo10.bin 8192
tools\pad .\src\bin\demo11_6000 .\src\bin\demo11.bin 8192
tools\pad .\src\bin\demo12_6000 .\src\bin\demo12.bin 8192
tools\pad .\src\bin\demo13_6000 .\src\bin\demo13.bin 8192
tools\pad .\src\bin\demo14_6000 .\src\bin\demo14.bin 8192
tools\pad .\src\bin\demo15_6000 .\src\bin\demo15.bin 8192
tools\pad .\src\bin\demo16_6000 .\src\bin\demo16.bin 8192
tools\pad .\src\bin\demo17_6000 .\src\bin\demo17.bin 8192
tools\pad .\src\bin\demo18_6000 .\src\bin\demo18.bin 8192
tools\pad .\src\bin\demo19_6000 .\src\bin\demo19.bin 8192
tools\pad .\src\bin\demo20_6000 .\src\bin\demo20.bin 8192
tools\pad .\src\bin\demo21_6000 .\src\bin\demo21.bin 8192
tools\pad .\src\bin\demo22_6000 .\src\bin\demo22.bin 8192
tools\pad .\src\bin\demo23_6000 .\src\bin\demo23.bin 8192
tools\pad .\src\bin\demo24_6000 .\src\bin\demo24.bin 8192
tools\pad .\src\bin\demo25_6000 .\src\bin\demo25.bin 8192
tools\pad .\src\bin\demo26_6000 .\src\bin\demo26.bin 8192
tools\pad .\src\bin\demo27_6000 .\src\bin\demo27.bin 8192
tools\pad .\src\bin\demo28_6000 .\src\bin\demo28.bin 8192
tools\pad .\src\bin\demo29_6000 .\src\bin\demo29.bin 8192
tools\pad .\src\bin\demo30_6000 .\src\bin\demo30.bin 8192
tools\pad .\src\bin\demo31_6000 .\src\bin\demo31.bin 8192
tools\pad .\src\bin\demo32_6000 .\src\bin\demo32.bin 8192
tools\pad .\src\bin\demo33_6000 .\src\bin\demo33.bin 8192
tools\pad .\src\bin\demo34_6000 .\src\bin\demo34.bin 8192
tools\pad .\src\bin\demo35_6000 .\src\bin\demo35.bin 8192

rem Concatenate
rem The number of banks we concatenate must be a power of 2. That is the last
rem bank is copied many times. The order these are copied in determines the
rem bank index of the bank. SO KEEP IT IN ORDER!
copy /b ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo1.bin+ ^
    .\src\bin\demo2.bin+ ^
    .\src\bin\demo3.bin+ ^
    .\src\bin\demo4.bin+ ^
    .\src\bin\demo5.bin+ ^
    .\src\bin\demo6.bin+ ^
    .\src\bin\demo7.bin+ ^
    .\src\bin\demo8.bin+ ^
    .\src\bin\demo9.bin+ ^
    .\src\bin\demo10.bin+ ^
    .\src\bin\demo11.bin+ ^
    .\src\bin\demo12.bin+ ^
    .\src\bin\demo13.bin+ ^
    .\src\bin\demo14.bin+ ^
    .\src\bin\demo15.bin+ ^
    .\src\bin\demo16.bin+ ^
    .\src\bin\demo17.bin+ ^
    .\src\bin\demo18.bin+ ^
    .\src\bin\demo19.bin+ ^
    .\src\bin\demo20.bin+ ^
    .\src\bin\demo21.bin+ ^
    .\src\bin\demo22.bin+ ^
    .\src\bin\demo23.bin+ ^
    .\src\bin\demo24.bin+ ^
    .\src\bin\demo25.bin+ ^
    .\src\bin\demo26.bin+ ^
    .\src\bin\demo27.bin+ ^
    .\src\bin\demo28.bin+ ^
    .\src\bin\demo29.bin+ ^
    .\src\bin\demo30.bin+ ^
    .\src\bin\demo31.bin+ ^
    .\src\bin\demo32.bin+ ^
    .\src\bin\demo33.bin+ ^
    .\src\bin\demo34.bin+ ^
    .\src\bin\demo35.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin+ ^
    .\src\bin\demo0.bin ^
    .\demo8.bin

rem Build rpk file
WHERE jar
@IF %ERRORLEVEL% NEQ 0 GOTO :end
jar -cvf ti99demo.rpk demo8.bin layout.xml
:end
