#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

void printKMax(int arr[], int n, int k) {
  deque<int> dq;
  if (k > n)
    return;

    copy(arr, arr + k, front_inserter(dq));

    auto maxVal = *max_element(dq.begin(), dq.end());
    printf("%d ", maxVal);

    for (int i = k; i < n; ++i) {
        dq.push_front(arr[i]);
        if (arr[i] >= maxVal) {
            maxVal = arr[i];
        } else {
          if (*(dq.end() - (i - k + 1)) == maxVal) {
            maxVal = *max_element(dq.begin(), dq.end() - (i - k + 1));
            }
        }
        printf("%d ", maxVal);
    }
    printf("\n");
}

int main() {

  int t;
  cin >> t;
  while (t > 0) {
    int n, k;
    cin >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}