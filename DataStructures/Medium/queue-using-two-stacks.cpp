#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    stack<int> pushStack;
    stack<int> popStack;

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            pushStack.push(x);
        }
        else
        {
            if (t == 2)
            {
                if (popStack.empty())
                {
                    while(!pushStack.empty())
                    {
                        popStack.push(pushStack.top());
                        pushStack.pop();
                    }
                }
                if (!popStack.empty()) popStack.pop();
            }
            else
            {
                if (popStack.empty())
                {
                    while(!pushStack.empty())
                    {
                        popStack.push(pushStack.top());
                        pushStack.pop();
                    }
                }
                cout << popStack.top() << '\n';
            }
        }
    }
    return 0;
}
