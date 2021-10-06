#include <iostream>
#include <stack>
using namespace std;

stack<int> S;

// Functions
bool isOperator(char);
bool isNumber(char);
int preformCal(char, int, int);
void EvaluatePostfix(string);

int main()
{
    string strn;
    cout << "Enter a String: ";
    cin >> strn;
    EvaluatePostfix(strn);
    cout << S.top() << endl;
}


bool isOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    return false;
}

bool isNumber(char C)
{
    if(C >= '0' && C <= '9')
        return true;
    return false;
}

int preformCal(char sign, int op1, int op2)
{
    if(sign == '+') return op1 + op2;
    else if(sign == '-') return op1 - op2;
    else if(sign == '*') return op1 * op2;
    else if(sign == '/') return op1 / op2;
    else // unexpected error
        return -1;
}

void EvaluatePostfix(string str)
{
    int op1, op2, result;
    
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ' || str[i] == ',' )
            continue;
        else if (isOperator(str[i]))
        {
            op1 = S.top(); S.pop();
            op2 = S.top(); S.pop();
            result = preformCal(str[i], op1, op2);
            S.push(result);
        }
        else if (isNumber(str[i]))
        {
            int temp;
            temp = str[i] -  '0';
            S.push(temp);
        }
    }
}