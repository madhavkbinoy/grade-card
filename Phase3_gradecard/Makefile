CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = grade_card
OBJS = main.o functions.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	del $(TARGET).exe $(OBJS)