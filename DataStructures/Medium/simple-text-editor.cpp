#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// append - Append string  to the end of .
// delete - Delete the last  characters of .
// print - Print the  character of .
// undo - Undo the last (not previously undone) operation of type  or , reverting  to the state it was in prior to that 
int main() {
    string s;
    int q;
    cin >> q;

    stack<string> st;
    while (q--)
    {
        int t;
        cin >> t;
        switch(t)
        {
            case 1:
            {
                string temp;
                cin >> temp;
                st.push(s);
                s += temp;
                break;
            }
            case 2:
            {
                int n;
                cin >> n;
                st.push(s);
                s.erase(s.begin() + s.size() - n, s.end());
                break;
            }
            case 3:
            {
                int k;
                cin >> k;
                cout << s[k-1] << '\n';
                break;
            }
            case 4:
            {
                if (!st.empty())
                {
                    s = st.top();
                    st.pop();
                }
                break;
            }
        }
    }
    return 0;
}
