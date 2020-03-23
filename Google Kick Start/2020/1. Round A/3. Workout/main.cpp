
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int N, K;
		cin >> N >> K;

		vector<int> sessions(N);
		vector<int> differences(N-1);

		for (int k = 0; k < K; k++) {

			for (int n = 0; n < N + k; n++) {
				cin >> sessions[n];
				if (n > 0) differences[n-1] = sessions[n] - sessions[n-1];
			}

			int index = max_element(differences.begin(), differences.end()) - differences.begin();
			sessions.insert(sessions.begin() + index + 1, sessions[index] + (differences[index] + 1));

		}

		int index = max_element(differences.begin(), differences.end()) - differences.begin();
		cout << differences[index] << endl;

	}

	return 0;
	
}