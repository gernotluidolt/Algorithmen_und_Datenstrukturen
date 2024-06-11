CC = g++
FLAGS = -I
OBJECT_FILES = main.o StackWithArray.o StackWithArrayException.o 
all: StackWithArray

clean:
	rm -rf StackWithArray StackWithArray.exe *.o 

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS).

StackWithArray: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).