#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    set<int> v;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int val;
            cin >> val;
            v.insert(val);
        }
        else
        {
            if (q == 2)
            {
                int val;
                cin >> val;
                v.erase(val);
            }
            else {
                cout << *v.begin() << '\n';
            }
        }
    }
    return 0;
}
