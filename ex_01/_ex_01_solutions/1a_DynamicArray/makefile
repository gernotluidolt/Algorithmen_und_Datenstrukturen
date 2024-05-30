CC = g++
FLAGS = -I
OBJECT_FILES = main.o DynamicArray.o 
all: DynamicArray

clean: 
	rm -rf DynamicArray DynamicArray.exe *.o 

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS).

DynamicArray: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).