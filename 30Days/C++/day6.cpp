#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    while(N--)
    {
        string s;
        cin >> s;

        string even;
        string odd;

        for (int i = 0; i < s.size(); i += 2)
        {
            even += s[i];
        }

        for (int i = 1; i < s.size(); i += 2)
        {
            odd += s[i];
        }

        std::cout << even << " " << odd << std::endl;
    }   
    return 0;
}
