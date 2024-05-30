#ifndef SINGLYLINKEDLIST_H // include guard
#define SINGLYLINKEDLIST_H


class Node {  
	public:  
		int data;  
		Node *next;

	public:      
		Node(int data) {
			this->data = data;  
        		this->next = nullptr;  
		};
};


class SinglyLinkedList 
{
	private:
		Node* head;
                int length;

	public:
		SinglyLinkedList();
		~SinglyLinkedList();

		void insertAtLast(int data); // Add a node at the end of list
		void insertAtFirst(int data); // Add a node at the begin of list
		
		// Print out the list
		void printList();

		void removeFirstNode(); // Delete the first node
		void removeLastNode(); // Delete the last node
		
		int getFirstNode(); // Return first node
		int getLastNode(); // Return last node

		bool isEmpty(); // Test if the list is empty
		int size(); // Return the size of the list

		/**********************************************************/
		/*         The following functions should not		  */ 
		/*            be defined for a linked list		  */
		/**********************************************************/

		void removeNodeAt(int position); // Delete the node at given position
		void insertAt(int position, int data); // Add a node at a given position within the list

};


#endif /* SINGLYLINKEDLIST_H */
