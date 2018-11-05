CC=clang++
FNAME=fltk_test2
# FLTKCONFIG = /usr/local/bin/fltk-config
INCLUDE=-I/usr/local/Cellar/fltk/1.3.4-2/include
LIBS=/usr/local/Cellar/fltk/1.3.4-2/lib/libfltk.a

namemake: $(FNAME).cpp
	$(CC) -I$(INCLUDE) -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -g -o ../a $(FNAME).cpp $(LIBS) -lpthread -framework Cocoa