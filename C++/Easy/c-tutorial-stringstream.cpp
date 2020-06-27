#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> res;
	istringstream strm(str);
    int num;
    char comma;
    while(strm)
    {
        strm >> num;
        strm >> comma;
        res.push_back(num);
    }

    return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}