CC = g++
FLAGS = -I
OBJECT_FILES = main.o StackWithLinkedList.o StackWithLinkedListException.o SinglyLinkedList.o SinglyLinkedListException.o
all: StackWithLinkedList

clean: 
	rm -rf StackWithLinkedList StackWithLinkedList.exe *.o 

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS).

StackWithLinkedList: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).