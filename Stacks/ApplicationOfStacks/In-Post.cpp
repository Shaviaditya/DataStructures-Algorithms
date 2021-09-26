//Program to convert an infix expression to postfix expression using stack
#include <iostream>
#include <stack>
using namespace std;
int precision(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string InfixToPostfix(string req)
{
    string res;
    stack<char> stk;
    for (int i = 0; i < req.length(); i++)
    {
        if ((req[i] >= 'a' && req[i] <= 'z') || (req[i] >= 'A' && req[i] <= 'Z') || (req[i] >= '0' && req[i] <= '9'))
        {
            res += req[i];
        }
        else if (req[i] == '(')
        {
            stk.push(req[i]);
        }
        else if (req[i] == ')')
        {
            while (!stk.empty() && stk.top() != '(')
            {
                res += stk.top();
                stk.pop();
            }
            if (!stk.empty())
            {
                stk.pop();
            }
        }
        else
        {
            while (!stk.empty() && precision(req[i]) <= precision(stk.top()))
            {
                res += stk.top();
                stk.pop();
            }
            stk.push(req[i]);
        }
    }
    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }
    return res;
}
//Driver Code
int main()
{
    string var;
    cin >> var;
    cout << InfixToPostfix(var) << endl;
    return 0;
}