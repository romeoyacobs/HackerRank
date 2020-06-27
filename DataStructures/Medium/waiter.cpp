#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

constexpr int primesN = 1201;
vector<int> primes(primesN);

constexpr int maxN = 10000;

void sieve()
{
    bool arr[maxN];
    for (int i = 0; i < maxN; ++i)
    {
        arr[i] = true;
    }
    arr[0] = arr[1] = false;

    for (int i = 2; i < maxN; ++i) {
      for (int j = i*i; j < maxN; j += i) {
        arr[j] = false;
      }
    }

    int k = 0;
    for (int i = 1; i < primesN; ++k)
    {
        if (arr[k] == true)
        {
            primes[i++] = k;
        }
    }
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> res;

    vector<stack<int>> bStacks;

    stack<int> aStack;
    for (auto el : number)
    {
        aStack.push(el);
    }

    for (int i = 0; i < q; ++i)
    {
        auto currStack = aStack;
        aStack = stack<int>();

        stack<int> bStack;

        while (!currStack.empty())
        {
            auto el = currStack.top();
            currStack.pop();
            if (el % primes[i + 1] == 0)
            {
                bStack.push(el);
            }
            else
            {
                aStack.push(el);
            }
        }

        bStacks.push_back(bStack);
    }

    bStacks.push_back(aStack);
    
    for (auto & stk : bStacks)
    {
        while (!stk.empty())
        {
            auto r = stk.top();
            stk.pop();
            res.push_back(r);
        }
    }
    return res;
}

int main()
{
    sieve();
    // for (int i = 1; i < 100; ++i)
    // {
    //     cout << primes[i] << " ";
    // }
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
