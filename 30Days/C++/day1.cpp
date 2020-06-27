#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int i2;
    std::cin >> i2;
    double d2;
    cin >> d2;
    string s2;
    getline(cin, s2);
    string s3;
    getline(cin, s3);
    cout << i + i2 << endl;
    cout << setprecision(1) << fixed << d + d2 << endl;
    cout << s + s3;
    // Declare second integer, double, and String variables.
    
    // Read and save an integer, double, and String to your variables.
    
    // Print the sum of both integer variables on a new line.
    
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    return 0;
}