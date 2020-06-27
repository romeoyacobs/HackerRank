#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        auto LeftPad = [](double B) {
            constexpr int totalLength{15};
            constexpr int floatingLength{2};
            constexpr int dotLength{1};
            constexpr int signLength{1};

            int intB = static_cast<int>(B);
            int bLength{1};
            while (intB /= 10) {
                ++bLength;
            }

            int paddingLength = totalLength - floatingLength - dotLength -
                                signLength - bLength;

            while (paddingLength--) {
            cout << "_";
            }
            cout << (B >= 0 ? "+" : "-");
            cout << setprecision(2) << fixed << B << '\n';
        };

        const long long Aint = static_cast<long long>(A);
        cout << std::nouppercase << setw(0) << fixed << "0x" << std::hex << Aint << endl;
        LeftPad(B);
        cout << std::uppercase << setprecision(9) << scientific << C << endl;
	}
	return 0;

}