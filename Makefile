CC = g++
CFLAGS  = -g -Wall
RM = rm

OPENCV = `pkg-config --cflags --libs opencv4`

lIBS = $(OPENCV)

all: main run

main: main.o Image.o
	$(CC) $(CFLAGS) -o main main.o Image.o $(lIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< $(lIBS)

run:
	./main
	
clean:
	rm *.o main