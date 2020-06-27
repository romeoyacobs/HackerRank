#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
   int N;
   cin >> N;

    unordered_map<string, long long> phoneBook;
    while (N--)
    {
        long long number;
        string name;

        cin >> name;
        cin >> number;

        phoneBook[name] = number;
    }

    string query;
    while (cin >> query)
    {
        auto itFound = phoneBook.find(query);
        if (itFound == phoneBook.end())
        {
            cout << "Not found" << endl;
        }
        else
        {
            cout << query << "=" << itFound->second << endl;
        }
    }
    return 0;
}
