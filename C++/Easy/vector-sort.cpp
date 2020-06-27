#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> res(N);
    for(vector<int>::size_type i = 0; i < N; ++i)
    {
        cin >> res[i];
    }

    sort(res.begin(), res.end());
    for_each(res.begin(), res.end(), [](int x) { cout << x << " "; });
    return 0;
}