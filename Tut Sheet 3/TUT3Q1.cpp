#include<iostream>
using namespace std;

void isfull(int stack[] ,int size,int top) {
    if (top == size - 1) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is not full" << endl;
    }
}

void isempty(int stack[], int size, int top) {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
}

void push(int stack[], int size , int value , int &top){
    if(top == size-1){
        cout<<"the stack is full "<<endl;
    }
    else{
        top++;
        stack[top] = value;
    }
}

void pop(int stack[] , int size , int &top){
    if(top == -1){
        cout<<"the stack is still empty nothing to pop "<<endl;
    }
    else{
        cout<<"the popped element is : "<<stack[top] << endl;
        top--;
    }
    }

    void peek (int stack[],int top){
        cout<<"the last element entered was : "<<stack[top] << endl;
    }

    void display(int stack[], int top) {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {

    cout<<"enter the size of the stack u want : ";
    int size;
    cin>>size;
    int stack[size];
    int top = -1;
    int s = 0 ;
    while(s==0){
        cout<<"enter the function you want to perform on the stack -- push pop isfull isempty peek display exit : ";
        string func;
        cin>>func;
        if(func == "push"){
            int value;
            cout<<"enter the value to be pushed : ";
            cin>>value;
            push(stack, size, value, top);
        }
        else if(func == "pop"){
            pop(stack, size, top);
        }
        else if(func == "isfull"){
            isfull(stack, size, top);
        }
        else if(func == "isempty"){
            isempty(stack, size, top);
        }
        else if(func == "peek"){
            peek(stack, top);
        }
        else if(func == "display"){
            display(stack, top);
        }
        else if(func == "exit"){
            s = 1 ; 
        }
        else{
            cout<<"invalid function name "<<endl;
        }
    }

    return 0;
}