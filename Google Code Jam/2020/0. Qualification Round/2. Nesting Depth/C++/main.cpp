
/*
 * By: 			Ruan Swanepoel
 * Completed: 	5/04/2020
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

	int T = 1;
	cin >> T;

	for (int t = 0; t < T; t++) {

		string s;
		cin >> s;

		// Extract digits from string
		std::vector<int> v;
		for (char c : s) {
			v.push_back(c - '0');
		}

		string result = "";

		//
		int depth = 0;
		for (int i = 0; i < v.size(); i++) {
			int diff = v[i] - depth;
			if (diff > 0) {
				for (int j = 0; j < diff; j++) {
					result += "(";
				}
			}
			else if (diff < 0) {
				for (int j = 0; j < (0-diff); j++) {
					result += ")";
				}
			}
			result += to_string(v[i]);
			depth = v[i];
		}

		for (int i = 0; i < depth; i++) {
			result += ")";
		}

		cout << "Case #" << t+1 << ": " << result << endl;

	}

	return 0;

}