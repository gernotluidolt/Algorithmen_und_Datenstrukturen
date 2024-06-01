#include "StackWithLinkedList.h"
#include "StackWithLinkedListException.cpp"

StackWithLinkedList::StackWithLinkedList()
{
    std::cout << "StackWithLinkedList created." << std::endl;
    head = NULL;
    length = 0;
}

StackWithLinkedList::~StackWithLinkedList()
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
    std::cout << "StackWithLinkedList destroyed." << std::endl;
}

void StackWithLinkedList::push(int value)
{
    std::cout << "Push: " << value << std::endl;
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    length++;
}

int StackWithLinkedList::pop()
{
    if (isEmpty())
    {
        throw StackWithLinkedListException("Cannot pop: Stack is empty!");
    }
    int value = head->data;
    std::cout << "Pop: " << value << std::endl;
    Node *temp = head;
    head = head->next;
    delete temp;
    length--;
    return value;
}

int StackWithLinkedList::peek()
{
    std::cout << "Peek: " << std::endl;
    if (isEmpty())
    {
        throw StackWithLinkedListException("Cannot peek: Stack is empty!");
    }
    return head->data;
}

bool StackWithLinkedList::isEmpty() const
{
    return length == 0;
}

void StackWithLinkedList::printStack() const
{
    std::cout << "Stack: " << std::endl;
    Node *temp = head;
    if (temp == NULL)
    {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    std::cout << "Number of elements in the stack: " << length << std::endl;
}
