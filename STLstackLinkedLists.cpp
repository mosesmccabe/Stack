/*   
         Stack - Linked lists & STL Stack
         1. create a linked lists
         2. add value to lists
         3.crate a stack of pointer (or stack of list)
         4. push linked lists address to stack
         5. set head/top of linked lists as the top value of stack
         6. using the stack to reverse the linked list;
         7. print linked lists
 
 https://www.youtube.com/watch?v=hNP72JdOIgY&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P
*/

#include<iostream>
#include<stack>
using namespace std;


struct Node
{
    int data;
    Node *next;
};
Node *top = nullptr;
stack<Node*> S;

void pushvalue(int userInput)
{
    Node *temp = new Node();
    temp->data = userInput;
    temp->next = top;
    top = temp;
}

void pushToStack( )
{
    Node *temp = top;
    
    while(temp != nullptr)
    {
        S.push(temp);
        temp = temp->next;
    }
}

void reverse()
{
    Node *temp = S.top();
    top = temp;
    
    while(!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
}

void print()
{
    Node *temp = top;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *temp;
    pushvalue(10);
    pushvalue(20);
    pushvalue(30);
    pushvalue(40);
    pushvalue(50);
    pushToStack();
    for ( ;!S.empty(); S.pop() )
    {
        temp = S.top();
        cout << temp->data << " ";
    }
    cout << endl;
    print();
    cout << endl;

}