/*

    Check for balanced parenthesis in a program.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check for match
bool match(char curr, char comp)
{
    if( (curr == '(') && (comp == ')') )
        return true;
    else if( (curr == '{') && (comp == '}') )
        return true;
    else if( (curr == '[') && (comp == ']') )
        return true;
    return false;
}

// Add value to stack
bool areParenthesisBalance(string str)
{
    stack<char> S;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            S.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(S.empty() || !match(S.top(), str[i]))
            {
                return false;
            }
            else
            {
                S.pop();
            }
        }
    }

    return S.empty() ? true:false;
}

int main()
{
    string userInput;
    cout << "Enter string: ";
    cin >> userInput;
    if (areParenthesisBalance(userInput))
        cout << "Parantheses is Balance\n";
    else
        cout << "Parentheses is not Balance\n";
    
    return 0;
}