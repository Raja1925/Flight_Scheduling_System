CC = gcc
CFLAGS = -Wall -g

OBJS = main.o flight.o
TARGET = scheduler.exe

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c flight.h
	$(CC) $(CFLAGS) -c main.c

flight.o: flight.c flight.h
	$(CC) $(CFLAGS) -c flight.c

clean:
	del *.o *.exe