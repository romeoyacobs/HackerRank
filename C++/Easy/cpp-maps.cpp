#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map<string, int> sheet;

    int Q;
    cin >> Q;

    while (Q--)
    {
        short type;
        string student;
        cin >> type >> student;

        switch (type)
        {
            case 1:
            {
                int mark;
                cin >> mark;
                sheet[student] += mark;
                break;
            }
            case 2:
            {
                sheet[student] = 0;
                break;
            }
            case 3:
            {
                cout << sheet[student] << endl;
                break;
            }
            default:
            break;
        }
    } 
    return 0;
}