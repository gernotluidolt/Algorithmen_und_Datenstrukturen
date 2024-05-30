#include "SinglyLinkedList.h"
#include "SinglyLinkedListException.cpp"
#include <iostream>


using namespace std;


SinglyLinkedList::SinglyLinkedList() 
{
	head = NULL;
        length = 0;
}


SinglyLinkedList::~SinglyLinkedList() 
{
	Node *temp1 = head;
	Node *temp2;

	// traverse the list and remove elements
	while (temp1 != NULL) 
	{
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
	length = 0;
}


void SinglyLinkedList::removeFirstNode() 
{
	removeNodeAt(1);
}


void SinglyLinkedList::removeLastNode() 
{
	removeNodeAt(length);
}


void SinglyLinkedList::removeNodeAt(int position) 
{
	Node *temp1 = head;
        Node *temp2 = NULL;

	if ( (head == NULL) || (length < 1) )
	{
		cout << "Cannot remove element: the list empty!" << endl;
		return;  // alternatively throw an exception
	}

	// Check if the position to delete is less than length of list
	if (position > length) 
	{
		cout << "Cannot remove noded at position " << position << ": Index out of range!" << endl;
		return;  // alternatively throw an exception
	}

	// Position on the first element
	temp1 = head;
	// Remove the first element by updating the reference to the head
	if (position == 1) 
	{
		head = head->next;
		delete temp1;
                --length;
		return;
	}

	// traverse the list to find the node to delete
	while (position > 1) 
	{

		temp2 = temp1;
		temp1 = temp1->next;
		--position;
	}
	// update pointers
	temp2->next = temp1->next;
	// delete the node
	delete temp1;
	--length;	
}


void SinglyLinkedList::insertAtLast(int data)
{
	// Create the new Node.
	Node* newNode = new Node(data);

	// If the list is empty, assign new element to head
	if (head == NULL) 
	{
		head = newNode;
		++length;
		return;
	}

	// Traverse list until the end
	Node* temp = head;
	while (temp->next != NULL) 
	{
		temp = temp->next;
	}
	// Add at the last position
	temp->next = newNode;
	++length;
}


void SinglyLinkedList::insertAtFirst(int data)
{
	// Create the new Node.
	Node* newNode = new Node(data);

	newNode->next = head;
	head = newNode;
	++length;
}


void SinglyLinkedList::insertAt(int position, int data)
{
	// Check if the position to delete is less than length of list
	if ( (position > length)  || (position < 1) )
	{
		cout << "Cannot insert element " << data << ": Index out of range!" << endl;
		return;  // alternatively throw an exception
	}

	// Create the new Node.
	Node* newNode = new Node(data);
	Node *curr = head;

	// Place in the first position?
	if (position == 1) 
	{
		head = newNode;
		newNode->next = curr;
		++length;
		return;
	}

	Node *prev = head;
	// traverse the list to the location where to add the new Node
	while (position > 1) 
	{
		prev = curr;
		curr = curr->next;
		--position;
	}

	// update pointers
	newNode->next = prev->next;
	prev->next = newNode;
	++length;
}


void SinglyLinkedList::printList()
{
	Node* temp = head;

	// Is list empty?
	if (head == NULL) 
	{
		cout << "List is empty!" << endl;
		return;  // alternatively throw an exception
	}

	// Traverse the list and print out element by element
	cout << "Elements: > ";
	while (temp != NULL) 
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "<" << endl
	     << "Total number of elements: " << length << endl;
}


int SinglyLinkedList::getFirstNode()
{
	// Is list empty?
	if (head == NULL) 
	{
		cout << "List is empty!" << endl;
		throw SinglyLinkedListException("List is empty!");
	}

	return head->data;
}

		
int SinglyLinkedList::getLastNode()
{
	// Is list empty?
	if (head == NULL) 
	{
		cout << "List is empty!" << endl;
		throw SinglyLinkedListException("List is empty!");
	}
	// Traverse list until the end
	Node* temp = head;
	while (temp->next != NULL) 
	{
		temp = temp->next;
	}
	return temp->data;
}


bool SinglyLinkedList::isEmpty()
{
	return length == 0;
}


int SinglyLinkedList::size()
{
	return length;
}
