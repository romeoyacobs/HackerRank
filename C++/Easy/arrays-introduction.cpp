#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> a(N);

    while(N--)
    {
        cin >> a[N];
    }

    for (size_t i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }

    return 0;
}