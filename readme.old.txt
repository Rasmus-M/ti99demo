readme.txt
5/10/2016

Should be pretty easy to build. Requires Python 2.7 to be in your PATH to run 
the assembler. Once you've got that setup, just run makecart.bat from the root 
directory. It will produce demo8.bin in the root directory which you can load 
with your favorite emulator. Alternately, run makedisk.bat to produce demo.dsk.
 You can load the demo using E/A option 5 and entering DSK#.DEMOA.

If you want to build it on Linux, you'll need gcc and python 2.7 installed.
Then just type 'make cart' or 'make disk' respectively.

There is also now a mailing list that will notify you of commits to the svn
server. Just email ti99demo-subscribe@orbitaldecay.com. Make sure you check
your spam folder and add the ti99demo@orbitaldecay.com addresses to your
whitelist!

SVN commit mailing list now also includes the commit log :)

Better yet, subversion commits are now being announced on the #subversion
channel at http://ti-994megademo.slack.com.

I've also included a launch script for MAME. If mame64.exe is already in your
path, simply run mame.bat from the root directory of this repository.

orbitaldecay (orbitaldecay@gmail.com)
