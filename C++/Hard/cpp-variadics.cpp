#include <iostream>
using namespace std;

#include <math.h>

template <bool head>
int reversed_binary_value(int deep) { return pow(2, deep) * head;
}

template <bool head, bool next, bool... tail>
int reversed_binary_value(int deep)
{
    return pow(2, deep++) * head + reversed_binary_value<next, tail...>(deep);
}

template <bool head, bool next, bool... tail>
int reversed_binary_value()
{
    int deep = 0;
    return pow(2, deep++) * head + reversed_binary_value<next, tail...>(deep);
}


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}