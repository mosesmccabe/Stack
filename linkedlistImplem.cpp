/*
      Stack - Linked lists implementation
     https://www.youtube.com/watch?v=MuwxQ2IB8lQ&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&t=2
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *top = nullptr;

void push(int userInput)
{
    Node *temp = new Node();
    temp->data = userInput;
    temp->next = top;
    top = temp;
}


bool isEmpty()
{
    if(top == nullptr)
        return true;
    else
        return false;
}

void pop()
{
    if (isEmpty() == true)
    {
        cout << "Stack is Empty\n";
        return;
    }
    Node *temp = top;
    top = temp->next;
    delete temp;
}


void print()
{
    Node *temp = top;
    if(isEmpty() == true)
    {
        cout << "Stack is Empty\n";
        return;
    }
    else
    {
        while(temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}




int main()
{
    push(6);
    push(10);
    push(15);
    push(20);
    print();
    pop();
    pop();
    print();
}