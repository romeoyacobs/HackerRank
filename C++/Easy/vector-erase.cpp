#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t N;
    cin >> N;

    vector<int> v(N);
    for_each(v.begin(), v.end(), [](int &el) { cin >> el; });

    size_t eraseIndex;
    cin >> eraseIndex;
    --eraseIndex;

    size_t startIndex, endIndex;
    cin >> startIndex >> endIndex;
    --startIndex;
    --endIndex;
    v.erase(v.begin() + eraseIndex);
    v.erase(v.begin() + startIndex, v.begin() + endIndex);

    cout << v.size() << std::endl;
    for_each(v.begin(), v.end(), [](int el) { cout << el << " "; });
    return 0;
}
