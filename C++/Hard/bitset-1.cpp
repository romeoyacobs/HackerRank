#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <stdint.h>

const uint32_t maxVal = UINT32_MAX;

int main() {
    uint64_t N, S, P, Q;
    cin >> N >> S >> P >> Q;

    uint32_t o = 1 << 31;
    vector<uint32_t> a(N);
    a[0] = S;
    for (int i = 1; i < N; ++i)
    {
        uint64_t temp = static_cast<uint64_t>(a[i - 1]) * P + Q;
        a[i] = temp % o;
    }

    //sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    //a.erase(it, a.end());
    cout << it - a.begin() << endl;

    //for_each(a.begin(), a.end(), [](uint32_t val) { cout << val << '\n'; });
    return 0;
}

