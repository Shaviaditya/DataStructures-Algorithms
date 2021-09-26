#include <iostream>
#include <stack>
using namespace std;
void insertBottom(stack<int> &stk, int x)
{
    if (stk.empty())
    {
        stk.push(x);
        return;
    }
    else
    {
        int val = stk.top();
        stk.pop();
        insertBottom(stk, x);
        stk.push(val);
    }
}
void reverse(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    int val = stk.top();
    stk.pop();
    reverse(stk);
    insertBottom(stk, val);
}

//Driver Code
int main()
{
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    reverse(stk);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    printf("\n");
    return 0;
}
