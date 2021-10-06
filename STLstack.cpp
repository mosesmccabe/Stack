#include <iostream>
#include <stack>
using namespace std;

void Reverse(char *array, int sizeOfArr)
{
    stack<char> S;
    
    // Push array onto stack
    for (int i = 0; i < sizeOfArr; i++)
    {
        S.push(array[i]);
    }
    
    // Pop value from stack
    for (int i = 0; i < sizeOfArr; i++)
    {
        array[i] = S.top();
        S.pop();
    }
}

int main()
{
    
    char arr[51];
//    cin.ignore;
    cout << "Enter a string: ";
    gets(arr);
    Reverse(arr, strlen(arr));
    cout << arr << endl;
}