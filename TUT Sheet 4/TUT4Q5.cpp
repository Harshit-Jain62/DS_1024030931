#include <iostream>
using namespace std;

const int SIZE = 10;
int q1[SIZE], q2[SIZE];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

void enqueue(int q[], int &f, int &r, int val) {
    if (r == SIZE - 1) {
        cout << "Queue is full" << endl;
        return;
    }
    if (f == -1) f = 0;
    q[++r] = val;
}

int dequeue(int q[], int &f, int &r) {
    if (f == -1) {
        return -1;
    }
    int val = q[f];
    if (f == r) {
        f = r = -1;
    } else {
        f++;
    }
    return val;
}

bool isEmpty(int f, int r) {
    return f == -1;
}

void displayQueue(int q[], int f, int r) {
    if (f == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = f; i <= r; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

class StackUsingTwoQueues {
public:
    void push(int val) {
        enqueue(q2, f2, r2, val);
        while (!isEmpty(f1, r1)) {
            int x = dequeue(q1, f1, r1);
            enqueue(q2, f2, r2, x);
        }
        swap(f1, f2);
        swap(r1, r2);
        cout << "Pushed: " << val << endl;
    }
    
    int pop() {
        if (isEmpty(f1, r1)) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int val = dequeue(q1, f1, r1);
        cout << "Popped: " << val << endl;
        return val;
    }
    
    int top() {
        if (isEmpty(f1, r1)) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int val = q1[f1];
        cout << "Top: " << val << endl;
        return val;
    }
    
    void display() {
        cout << "Stack (Two Queues): ";
        displayQueue(q1, f1, r1);
    }
};

class StackUsingOneQueue {
private:
    int q[SIZE];
    int f = -1, r = -1;
    
    void enqueueSingle(int val) {
        if (r == SIZE - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if (f == -1) f = 0;
        q[++r] = val;
    }
    
    int dequeueSingle() {
        if (f == -1) {
            return -1;
        }
        int val = q[f];
        if (f == r) {
            f = r = -1;
        } else {
            f++;
        }
        return val;
    }
    
    bool isEmptySingle() {
        return f == -1;
    }
    
    int getSize() {
        if (f == -1) return 0;
        return r - f + 1;
    }
    
public:
    void push(int val) {
        int n = getSize();
        enqueueSingle(val);
        for (int i = 0; i < n; i++) {
            int x = dequeueSingle();
            enqueueSingle(x);
        }
        cout << "Pushed: " << val << endl;
    }
    
    int pop() {
        if (isEmptySingle()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int val = dequeueSingle();
        cout << "Popped: " << val << endl;
        return val;
    }
    
    int top() {
        if (isEmptySingle()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int val = q[f];
        cout << "Top: " << val << endl;
        return val;
    }
    
    void display() {
        if (f == -1) {
            cout << "Stack (One Queue): Empty" << endl;
            return;
        }
        cout << "Stack (One Queue): ";
        for (int i = f; i <= r; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

void displayMenu() {
    cout << "\nStack Implementation Menu\n";
    cout << "1. Stack using Two Queues - Push\n";
    cout << "2. Stack using Two Queues - Pop\n";
    cout << "3. Stack using Two Queues - Top\n";
    cout << "4. Stack using Two Queues - Display\n";
    cout << "5. Stack using One Queue - Push\n";
    cout << "6. Stack using One Queue - Pop\n";
    cout << "7. Stack using One Queue - Top\n";
    cout << "8. Stack using One Queue - Display\n";
    cout << "9. Exit\n";
    cout << "Choose: ";
}

int main() {
    StackUsingTwoQueues stackTwoQueues;
    StackUsingOneQueue stackOneQueue;
    int choice, val;
    
    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> val;
            stackTwoQueues.push(val);
        }
        else if (choice == 2) {
            stackTwoQueues.pop();
        }
        else if (choice == 3) {
            stackTwoQueues.top();
        }
        else if (choice == 4) {
            stackTwoQueues.display();
        }
        else if (choice == 5) {
            cout << "Enter value to push: ";
            cin >> val;
            stackOneQueue.push(val);
        }
        else if (choice == 6) {
            stackOneQueue.pop();
        }
        else if (choice == 7) {
            stackOneQueue.top();
        }
        else if (choice == 8) {
            stackOneQueue.display();
        }
        else if (choice == 9) {
            cout << "You have exited the menu" << endl;
            break;
        }
        else {
            cout << "Enter a valid menu option" << endl;
        }
    }
    
    return 0;
}