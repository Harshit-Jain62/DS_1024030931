#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *next, *prev;
    node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class dll {
    node *head;
public:
    dll() { head = NULL; }

    void push_front(int val) {
        node* newnode = new node(val);
        if (head == NULL) head = newnode;
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void push_back(int val) {
        node* newnode = new node(val);
        if (head == NULL) head = newnode;
        else {
            node* curr = head;
            while(curr->next != NULL) curr = curr->next;
            curr->next = newnode;
            newnode->prev = curr;
        }
    }

    void push_after(int val, int key) {
        node* newnode = new node(val);
        node *curr = head;
        while(curr != NULL && curr->data != key) curr = curr->next;
        if (curr == NULL) return;
        newnode->next = curr->next;
        newnode->prev = curr;
        if (curr->next != NULL) curr->next->prev = newnode;
        curr->next = newnode;
    }

    void push_before(int val, int key) {
        node* newnode = new node(val);
        if (head->data == key) push_front(val);
        else {
            node *curr = head;
            while(curr != NULL && curr->data != key) curr = curr->next;
            if (curr == NULL) return;
            newnode->next = curr;
            newnode->prev = curr->prev;
            curr->prev->next = newnode;
            curr->prev = newnode;
        }
    }

    void del_front() {
        if (head == NULL) return;
        node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
    }

    void del_back() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            node* temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->prev->next = NULL;
            delete temp;
        }
    }

    void del_val(int key) {
        if (head == NULL) return;
        if (head->data == key) del_front();
        else {
            node* curr = head;
            while(curr != NULL && curr->data != key) curr = curr->next;
            if (curr == NULL) return;
            if (curr->next != NULL) curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            delete curr;
        }
    }

    bool search(int key) {
        node* curr = head;
        while(curr != NULL) {
            if (curr->data == key) return true;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        node* curr = head;
        while(curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    dll list;
    int choice, val, key;
    
    do {
        cout << "1.Insert Front 2.Insert Back 3.Insert After 4.Insert Before\n";
        cout << "5.Delete Front 6.Delete Back 7.Delete Value 8.Search 9.Display 10.Exit\n";
        cin >> choice;
        
        switch(choice) {
            case 1: cin >> val; list.push_front(val); break;
            case 2: cin >> val; list.push_back(val); break;
            case 3: cin >> val >> key; list.push_after(val, key); break;
            case 4: cin >> val >> key; list.push_before(val, key); break;
            case 5: list.del_front(); break;
            case 6: list.del_back(); break;
            case 7: cin >> key; list.del_val(key); break;
            case 8: cin >> key; cout << (list.search(key)?"Found":"Not found") << endl; break;
            case 9: list.display(); break;
        }
    } while(choice != 10);
    
    return 0;
}