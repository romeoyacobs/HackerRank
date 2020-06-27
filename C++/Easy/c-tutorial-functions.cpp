#include <iostream>
#include <cstdio>

#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int max_of_four(int a, int b, int c, int d)
{
  std::vector<int> list = {a, b, c, d};
  std::sort(begin(list), end(list), std::greater<int>{});
  return *list.begin();
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}