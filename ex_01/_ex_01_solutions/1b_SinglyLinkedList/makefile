CC = g++
FLAGS = -I
OBJECT_FILES = main.o SinglyLinkedList.o SinglyLinkedListException.o
all: SinglyLinkedList

clean: 
	rm -rf SinglyLinkedList SinglyLinkedList.exe *.o 

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS).

SinglyLinkedList: $(OBJECT_FILES)
	$(CC) -o $@ $^ $(FLAGS).