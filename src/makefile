# compiler flags
CC = gcc
CFLAGS = -g

# files
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# linker
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# executable
TARGET = marijuana-scroll

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCS) $(LIBS)

clean:
	rm -rf *.o
