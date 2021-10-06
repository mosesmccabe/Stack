/*  
     Array based implementation of stack
     https://www.youtube.com/watch?v=sFVxsglODoo&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&t=2
*/
#include<iostream> 
using namespace std;

const int MAX_SIZE = 101;
int A[MAX_SIZE];
int top = -1;

// push
void push(int userInput)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Stack overflow\n";
        return;
    }
    A[++top] = userInput;
}

// pop
void pop()
{
    if (top == -1)
    {
        cout << "No element to pop\n";
        return;
    }
    top--;
}

// top
int topFun()
{
    return A[top];
}

// Empty
bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}


void printStack()
{
    for(int i = 0; i <= top; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    push(4);
    push(10);
    push(20);
    printStack();
    pop();
    push(9);
    cout << "top: " << topFun() << "\n";
    if (isEmpty() == false)
        printStack();
    else
        cout << "Stack is empty\n";
    return 0;
}
