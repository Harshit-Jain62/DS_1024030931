#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* head = NULL;

int main() {
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = 7;
    
    for(int i = n-1; i >= 0; i--) {
        Node* newNode = new Node();
        newNode->value = arr[i];
        newNode->next = head;
        head = newNode;
    }
    
    cout << "Original Linked List: ";
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    
    int key = 1;
    int count = 0;
    
    temp = head;
    while(temp != NULL) {
        if(temp->value == key) {
            count++;
        }
        temp = temp->next;
    }
    
    cout << "Count: " << count << endl;
    
    while(head != NULL && head->value == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    
    if(head != NULL) {
        Node* current = head;
        while(current->next != NULL) {
            if(current->next->value == key) {
                Node* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            } else {
                current = current->next;
            }
        }
    }
    
    cout << "Updated Linked List: ";
    temp = head;
    while(temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    
    return 0;
}