
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		int N, B;
		cin >> N >> B;

		vector<int> houses;

		for (int j = 0; j < N; j++) {
			int val;
			cin >> val;
			houses.push_back(val);
		}

		sort(houses.begin(), houses.end());

		int sum = 0;
		int num = 0;

		for (int j = 0; j < N; j++) {
			sum += houses[j];
			if (sum > B) break;
			num++;
		}

		cout << "Case #" << i+1 << ": " << num << endl;

	}

	return 0;

}