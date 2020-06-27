#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n);
    for (size_t k = 0; k < n; ++k)
    {
      int l;
      cin >> l;

      vector<int> temp(l);
      for (size_t i = 0; i < l; ++i) {
        cin >> temp[i];
      }
      arr[k] = temp;
    }

    while (q--)
    {
        int i, j;
        cin >> i >> j;

        cout << arr[i][j] << '\n';
    }  
    return 0;
}