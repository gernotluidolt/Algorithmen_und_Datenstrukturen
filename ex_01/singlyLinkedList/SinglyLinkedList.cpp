#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool SinglyLinkedList::isEmpty() const {
    return head == nullptr;
}

int SinglyLinkedList::getSize() const {
    return size;
}

void SinglyLinkedList::insertAtFirst(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    size++;
}

void SinglyLinkedList::insertAtLast(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

bool SinglyLinkedList::remove(int data) {
    if (isEmpty()) return false;

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        size--;
        return true;
    }
    return false;
}

bool SinglyLinkedList::search(int data) const {
    Node* temp = head;
    while (temp) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void SinglyLinkedList::printList() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

void SinglyLinkedList::removeLastNode() {
    if (isEmpty()) {
        std::cout << "List is empty, nothing to remove." << std::endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        delete secondLast->next;
        secondLast->next = nullptr;
    }
    size--;
}

void SinglyLinkedList::removeFirstNode() {
    if (isEmpty()) {
        std::cout << "List is empty, nothing to remove." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

void SinglyLinkedList::insertAt(int index, int data) {
    if (index < 0 || index > size) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    Node* newNode = new Node(data);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    size++;
}

void SinglyLinkedList::removeNodeAt(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    size--;
}