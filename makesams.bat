rem Assemble
python tools\xdt99\xas99.py -i -R -D SAMS -L controller.lst -o .\src\bin\samsdemo .\src\controller\controller.a99

rem Create disk
if not exist demo.dsk (
    python tools\xdt99\xdm99.py demo.dsk --initialize 720 -n DEMO
)

python tools\xdt99\xdm99.py demo.dsk -a ^
    .\src\bin\samsdemo ^
    -n SAMSDEMO
