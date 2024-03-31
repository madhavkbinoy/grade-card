
CC = gcc

CFLAGS = -Wall -Wextra -std=c99 
SRCS = grade_calc.c main.c exam_marks_entry.c print_grade_card.c student_info.c
OBJS = $(SRCS:.c=.o)

TARGET = program

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -f $(OBJS) $(TARGET)

