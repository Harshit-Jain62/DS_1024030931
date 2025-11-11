#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* head = NULL;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    for(int i = n-1; i >= 0; i--) {
        Node* newNode = new Node();
        newNode->value = arr[i];
        newNode->next = head;
        head = newNode;
    }
    
    cout << "Linked List: ";
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << "Middle: " << slow->value << endl;
    
    return 0;
}