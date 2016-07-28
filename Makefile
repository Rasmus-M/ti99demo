tools:
	gcc tools/bin2a99.c -o tools/bin2a99
	gcc tools/pad.c -o tools/pad
	gcc tools/split.c -o tools/split
cart:
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo0 --base 0x6000 ./src/controller/controller.a99
	./tools/pad ./src/bin/demo0_6000 ./src/bin/demo0.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo1 --base 0x6000 ./src/effects/lena/LENAP.A99 
	./tools/pad ./src/bin/demo1_6000 ./src/bin/demo1.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo2 --base 0x6000 ./src/effects/lena/LENAC.A99 
	tools/pad ./src/bin/demo2_6000 ./src/bin/demo2.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo3 --base 0x6000 ./src/effects/dotfx/dotfx.a99
	./tools/pad ./src/bin/demo3_6000 ./src/bin/demo3.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo4 --base 0x6000 ./src/effects/lena/LOADLENA.A99 
	./tools/pad ./src/bin/demo4_6000 ./src/bin/demo4.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo5 --base 0x6000 ./src/effects/music/songbank1.a99 
	./tools/pad ./src/bin/demo5_6000 ./src/bin/demo5.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo6 --base 0x6000 ./src/effects/raycaster/raycaster.a99
	./tools/pad ./src/bin/demo6_6000 ./src/bin/demo6.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo7 --base 0x6000 ./src/effects/raycaster/casterdata.a99
	./tools/pad ./src/bin/demo7_6000 ./src/bin/demo7.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo8 --base 0x6000 ./src/effects/squaretunnel/squaretunnel.a99
	./tools/pad ./src/bin/demo8_6000 ./src/bin/demo8.bin 8192
	python tools/xdt99/xas99.py -b -R -D CARTRIDGE -o ./src/bin/demo9 --base 0x6000 ./src/effects/metaballs/metaballs.a99
	./tools/pad ./src/bin/demo9_6000 ./src/bin/demo9.bin 8192
	cat \
	./src/bin/demo0.bin \
	./src/bin/demo1.bin \
	./src/bin/demo2.bin \
	./src/bin/demo3.bin \
	./src/bin/demo4.bin \
	./src/bin/demo5.bin \
	./src/bin/demo5.bin \
	./src/bin/demo5.bin \
	./src/bin/demo6.bin \
	./src/bin/demo7.bin \
	> ./demo8.bin

disk:
	python tools/xdt99/xas99.py -i -R -o ./src/bin/demo0 ./src/controller/controller.a99
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo1 ./src/effects/lena/LENAP.A99 
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo2 ./src/effects/lena/LENAC.A99 
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo3 ./src/effects/dotfx/dotfx.a99 
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo4 ./src/effects/lena/LOADLENA.A99
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo5 ./src/effects/music/songbank1.a99
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo6 ./src/effects/raycaster/raycaster.a99
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo7 ./src/effects/raycaster/casterdata.a99
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo8 ./src/effects/squaretunnel/squaretunnel.a99
	python tools/xdt99/xas99.py -b -R -o ./src/bin/demo9 ./src/effects/metaballs/metaballs.a99
	python tools/xdt99/xdm99.py demo.dsk --initialize 720 -n DEMO
	python tools/xdt99/xdm99.py demo.dsk -a \
        ./src/bin/demo0 \
        ./src/bin/demo1_0000 \
	./src/bin/demo2_0000 \
	./src/bin/demo3_0000 \
	./src/bin/demo4_0000 \
	./src/bin/demo5_0000 \
	./src/bin/demo6_0000 \
	./src/bin/demo7_0000 \
	-n DEMOA

