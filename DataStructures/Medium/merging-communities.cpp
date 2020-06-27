#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

template <class T> class UnionFind {
public:
  explicit UnionFind(T size);
  void unite(T v, T w);
  bool connected(T v, T w) const;
  T ComponentSize(T v) const;

private:
  T root(T v) const;

private:
  mutable std::vector<T> ids;
  std::vector<T> sz;
};

template <class T> UnionFind<T>::UnionFind(T size) {
  ids.resize(size);
  sz.resize(size);
  std::iota(ids.begin(), ids.end(), T{});
  std::fill(sz.begin(), sz.end(), T{1});
}

template <class T> bool UnionFind<T>::connected(T v, T w) const {
  return root(v) == root(w);
}

template <class T> T UnionFind<T>::ComponentSize(T v) const {
    auto rootV = root(v);
    return sz.at(rootV);
}

template <class T> void UnionFind<T>::unite(T v, T w) {
  auto rootV = root(v);
  auto rootW = root(w);
  if (rootV == rootW) {
    return;
  }

  if (sz.at(rootV) < sz.at(rootW)) {
    ids.at(rootV) = rootW;
    sz.at(rootW) += sz.at(rootV);
  } else {
    ids.at(rootW) = rootV;
    sz.at(rootV) += sz.at(rootW);
  }
}

template <class T> T UnionFind<T>::root(T v) const {
  while (ids.at(v) != v) {
    ids.at(v) = ids.at(ids.at(v));
    v = ids.at(v);
  }
  return v;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind<int> uf(N);
    while (Q--)
    {
        char c;
        cin >> c;
        if (c == 'Q')
        {
            int m;
            cin >> m;
            cout << uf.ComponentSize(m-1) << '\n';
        }
        else
        {
            int v, w;
            cin >> v >> w;
            uf.unite(v-1, w-1);
        }
    }  
    return 0;
}
