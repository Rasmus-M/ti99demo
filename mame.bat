@echo off
rem This script assumes mame64.exe is in your path.
mamed ti99_4a -peb:slot8 tifdc -peb:slot2 32kmem -flop1 demo.dsk -cart .\roms\editor_assembler.rpk -window -skip_gameinfo -nofilter -rompath .\roms -debug