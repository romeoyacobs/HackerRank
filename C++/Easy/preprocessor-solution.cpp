#define toStr(symbs) #symbs
#define io(vec) cin >> vec
#define FUNCTION(name, op) void name(int& a, int b) { a = (a op b) ? a : b; }
#define INF INT32_MAX
#define foreach(v, i) for (int i = 0; i < v.size(); ++ i)
#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}