# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Target executable
TARGET = my_program

# Source files
SRCS = main.c Eq_4_CapacityCorrectionFactor.c

# Object files (one for each source)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)