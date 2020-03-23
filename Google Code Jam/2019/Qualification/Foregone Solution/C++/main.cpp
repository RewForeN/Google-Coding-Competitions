
#include <iostream>
#include <string>

using namespace std;


int main() {

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		string N;
		cin >> N;
		string A = "";
		string B = "";
		for (char c : N) {
			if (c == '4') {
				A += '2';
				B += '2';
			}
			else {
				A += c;
				if (B != "") B += '0';
			}
		}
		cout << "Case #" << i+1 << ": " << A << " " << B << endl;
	}

}
