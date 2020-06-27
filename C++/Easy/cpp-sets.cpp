#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<long long> res;

    size_t Q;
    cin >> Q;

    while (Q--)
    {
        int type;
        cin >> type;

        set<long long>::value_type val;
        cin >> val;

        switch(type)
        {
            case 1:
            {
                res.insert(val);
                break;
            }
            case 2:
            {
                auto found = res.find(val);
                if (found != res.end())
                {
                    res.erase(found);
                }
                break;
            }
            case 3:
            {
              auto found = res.find(val);
              if (found != res.end()) {
                cout << "Yes\n";
              }
              else
              {
                  cout << "No\n";
              }
              break;
            }
            default:
            break;
        }
    }
    return 0;
}