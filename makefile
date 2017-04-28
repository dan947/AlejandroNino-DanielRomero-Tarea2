CC = gcc
CC_OPTIONS =   -O2 -Wall 
EXEC = euler.x
LIBS = -lm 

OBJS = struct.o diff.o converter.o init.o io.o main.o 
INCL = Makefile struct.h io.h init.h converter.h diff.h



.c.o:
	$(CC) $(CC_OPTIONS) -c $<


exec:$(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(EXEC)
	$(CC) shock.c -lm 
sedov:	
	./euler.x > euler.dat
shock:
	./a.out > data.dat
plotshock:
	python grf.py
plotsedov:
	python graficas.py
clean:
	rm -f $(OBJS) *~ core* ${EXEC}CC = gcc
