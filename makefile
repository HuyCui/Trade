all:main libmytrade.a
main:
	gcc -g -o main ./view/*.c ./controller/*.c main.c ./algorithm/*.c -I ./view -I ./controller -I ./algorithm `pkg-config --cflags --libs gtk+-2.0` -export-dynamic
libmytrade.a:./view/*.c ./controller/*.c main.c ./algorithm/*.c
	ar cr libmytrade.a ./view/*.c ./controller/*.c main.c ./algorithm/*.c
clean:
	rm -f *~ *.o main
	cd view && rm -f *~
	cd controller && rm -f *~
	cd algorithm && rm -f *~
