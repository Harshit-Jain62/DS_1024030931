#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = NULL; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    int getSize() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() { head = NULL; }

    void insert(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    int getSize() {
        if (head == NULL) return 0;
        
        int count = 0;
        CNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;

    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);

    cll.insert(5);
    cll.insert(15);
    cll.insert(25);

    cout << "Size of Doubly Linked List: " << dll.getSize() << endl;
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;

    return 0;
}