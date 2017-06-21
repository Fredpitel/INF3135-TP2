CC = gcc
OPTIONS = -Wall
EXE = tp2
OBJS = main.o liste.o stats.o

.SUFFIXES: .c .o

all: link

compile: $(OBJS)

.c .o:
	$(CC) $(OBJS) -o $(EXE)
	
link: compile
	$(CC) $(OBJS) -o $(EXE)
	
clean:
	rm $(EXE)
	rm $(OBJS)
	
start: link
	./$(EXE)
