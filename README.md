# TI-99/4A megademo

Should be pretty easy to build. Requires Python 2.7 to be in your PATH to run 
the assembler. Once you've got that setup, just run makecart.bat from the root 
directory. It will produce demo8.bin in the root directory which you can load 
with your favorite emulator. Alternately, run makedisk.bat to produce demo.dsk.
 You can load the demo using E/A option 5 and entering DSK#.DEMOA.

If you want to build it on Linux, you'll need gcc and python 2.7 installed.
Then just type 'make cart' or 'make disk' respectively.
**Note: This has not been kept up to date.**

I've also included a launch script for MAME. If mame64.exe is already in your
path, simply run mame.bat from the root directory of this repository.

orbitaldecay (orbitaldecay@gmail.com)
