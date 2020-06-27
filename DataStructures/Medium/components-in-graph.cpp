#include <bits/stdc++.h>

using namespace std;

class QuickUnionUF
{
 private:
    vector<int> id;
 public:
    QuickUnionUF(int N) {
        id.resize(N);
        for (int i = 0; i < N; i++) id[i] = i;
    }

    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

private:
    int root(int i) {
        while (i != id[i]) i = id[i];
        return i;
    }
};

class QuickFindUF
{
private:
  vector<int> id;
  int maxN;
  int minN;
public:
    QuickFindUF(int N) : maxN{1}, minN{INT_MAX}  {
        id.resize(N);
        for (int i = 0; i < N; ++i)
        {
            id[i] = i;
        }
    }
    bool connected(int p, int q)
    {
        return id[p] == id[q];
    }

    void unite(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];
        int currCompSize = 0;
        for (int i = 0; i < id.size(); ++i)
        {
            if (id[i] == qid)
            {
                ++currCompSize;
            }
            if (id[i] == pid)
            {
                id[i] = qid;
                ++currCompSize;
            }
        }
        maxN = max(maxN, currCompSize);
    }

    int getMax()
    {
        return maxN;
    }
    int getMin()
    {
        sort(id.begin(), id.end());
        int curr_el = id[0];
        int cnt {0};
        for (int i = 0; i < id.size(); ++i)
        {
            if (id[i] == curr_el)
            {
                ++cnt;
            }
            else
            {
                curr_el = id[i];
                minN = cnt != 1 ? min(minN, cnt) : minN;
                cnt = 1;
            }
        }
        minN = cnt != 1 ? min(minN, cnt) : minN;

        return minN;
    }
};

vector<int> componentsInGraph(vector<vector<int>> gb) {
    QuickFindUF qf(gb.size() * 2 + 1);
    for (int i = 0; i < gb.size(); ++i)
    {
        if (!qf.connected(gb[i][0], gb[i][1]))
        {
            qf.unite(gb[i][0], gb[i][1]);
        }
    }

    return {qf.getMin(), qf.getMax()};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < result.size(); SPACE_itr++) {
        fout << result[SPACE_itr];

        if (SPACE_itr != result.size() - 1) {
          fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
