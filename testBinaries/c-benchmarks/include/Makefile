all: print.o fatal.o
	
print.o: print.c print.h
	${CC} ${CFLAGS} -c print.c

fatal.o: fatal.c fatal.h
	${CC} ${CFLAGS} -c fatal.c

clean:
	rm -f *.o
