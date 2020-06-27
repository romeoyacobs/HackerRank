#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


int main() {
    int N;
    cin >> N;

    stack<long long> s;
    stack<long long> mx;
    for (int i = 0; i < N; ++i)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            long long x;
            cin >> x;
            s.push(x);
            if (mx.empty() || x >= mx.top())
            {
                mx.push(x);
            }
        }
        else
        {
            if (q == 2)
            {
                if (s.top() == mx.top())
                {
                    mx.pop();
                }
                s.pop();
            }
            else
            {
                cout << mx.top() << '\n';
            }
        }
    } 
    return 0;
}
