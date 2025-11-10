#include<iostream>
using namespace std;

int prec(char ch){
    if (ch=='+'||ch=='-')
    {
        return 1;
    }
    else if (ch=='*'||ch=='/')
    {
        return 2;
    }
    // else if(ch =='**'){
    //     return 3;
    // }
    else{
        return -1;
    }
}

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
        cout<<stack[top]<< endl;
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

int stack[100];
int top = -1;
char inexp[100];
cout<<"enter the expression in infix form to be converted to postfix form : ";
cin>>inexp;

int length = 0 ;
int i = 0 ;
while (inexp[i]!='\0')
{
    length++;
    i++;
}

cout<<"the length of the infix expression is : "<<length<<endl;

for (int i = 0; i <= length; i++)
{
    if (inexp[i]  != '+' && inexp[i]  != '-' && inexp[i]  != '*' &&inexp[i] != '/' && inexp[i]  != '(' && inexp[i]  != ')' )
    {
        cout<<inexp[i];
    }
    else if (inexp[i]  == '+' && inexp[i]  == '-' && inexp[i]  == '*' &&inexp[i] == '/' && inexp[i]  == '(' && inexp[i]  == ')')
    {
        if (top == -1)
        {
            push(stack,100,inexp[i],top);
        }
        else {
       while( (prec (stack[top])>= prec(inexp[i]))){
       pop(stack,100,top);
       }
       push(stack,100,inexp[i],top);
        }
    }
    
}



}