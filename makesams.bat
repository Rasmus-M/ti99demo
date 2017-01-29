rem Assemble
python tools\xdt99\xas99.py -i -R -D SAMS -L controller.lst -o .\src\bin\samsdemo .\src\controller\controller.a99

rem Create disk
if not exist demo-dsdd.dsk (
    python tools\xdt99\xdm99.py demo-dsdd.dsk --initialize DSDD -n DEMO
)

python tools\xdt99\xdm99.py demo-dsdd.dsk -a ^
    .\src\bin\samsdemo ^
    -n SAMSDEMO
