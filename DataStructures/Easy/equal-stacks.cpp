#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the equalStacks function below.
 */
long long equalStacks(vector<int> s1, vector<int> s2, vector<int> s3) {
    long long h1 = accumulate(s1.begin(), s1.end(), 0ll);
    long long h2 = accumulate(s2.begin(), s2.end(), 0ll);
    long long h3 = accumulate(s3.begin(), s3.end(), 0ll);

    while (!s1.empty() && !s2.empty() && !s3.empty())
    {
        if (h1 == h2 && h1 == h3 && h2 == h3) return h1;

        if (h1 >= h2 && h1 >= h3)
        {
            h1 -= s1.back();
            s1.pop_back();
            continue;
        }
        if (h2 >= h1 && h2 >= h3)
        {
            h2 -= s2.back();
            s2.pop_back();
            continue;
        }
        if (h3 >= h1 && h3 >= h1)
        {
            h3 -= s3.back();
            s3.pop_back();
        }
    }

    vector<long long> sizes{h1, h2, h3};
    auto min_el = min_element(sizes.begin(), sizes.end());
    return *min_el;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n1N2N3_temp;
    getline(cin, n1N2N3_temp);

    vector<string> n1N2N3 = split_string(n1N2N3_temp);

    int n1 = stoi(n1N2N3[0]);

    int n2 = stoi(n1N2N3[1]);

    int n3 = stoi(n1N2N3[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split_string(h1_temp_temp);

    vector<int> h1(n1);

    for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
        int h1_item = stoi(h1_temp[h1_itr]);

        h1[n1 - h1_itr - 1] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split_string(h2_temp_temp);

    vector<int> h2(n2);

    for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
        int h2_item = stoi(h2_temp[h2_itr]);

        h2[n2 - h2_itr - 1] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split_string(h3_temp_temp);

    vector<int> h3(n3);

    for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
        int h3_item = stoi(h3_temp[h3_itr]);

        h3[n3 - h3_itr - 1] = h3_item;
    }

    long long result = equalStacks(h1, h2, h3);

    fout << result << "\n";

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
