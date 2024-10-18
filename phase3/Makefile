CC=gcc
CFLAGS=-I.
DEPS = functions.h
OBJ = main.o functions.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

student_management: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o student_management
