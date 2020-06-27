#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    if (s.empty()) return "NO";

    stack<char> st;
    int i = 0;
    st.push(s[i++]);

    while (i < s.size())
    {
        auto c = s[i];
        switch(c)
        {
            case '}':
            {
                if (st.empty()) return "NO";
                auto c2 = st.top();
                if (c2 != '{') return "NO";
                st.pop();
                break;
            }
            case ')':
            {
                if (st.empty()) return "NO";
                auto c2 = st.top();
                if (c2 != '(') return "NO";
                st.pop();
                break;
            }
            case ']':
            {
                if (st.empty()) return "NO";                
                auto c2 = st.top();
                if (c2 != '[') return "NO";
                st.pop();
                break;
            }
            default:
            {
                st.push(c);
            }
        }
        ++i;
    }
    return st.empty() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
