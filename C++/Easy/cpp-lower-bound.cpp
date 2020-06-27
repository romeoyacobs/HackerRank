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
    for_each(v.begin(), v.end(), [](int& val) { cin >> val; });

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        size_t val;
        cin >> val;

        auto findVal = lower_bound(v.begin(), v.end(), val);
        string result {"No "};
        if (*findVal == val)
        {
            result = "Yes ";
        }

        cout << result << (findVal - v.begin() + 1) << endl;
    }
    return 0;
}
