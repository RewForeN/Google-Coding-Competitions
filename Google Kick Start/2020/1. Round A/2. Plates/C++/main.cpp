
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int plates_score(int max, int depth, int num, int index, vector<queue<int>> _plates) {

	if (depth >= max) return 0;

	vector<queue<int>> plates = _plates;

	int maxScore = 0;
	for (int i = 0; i < num; i++) {
		if (plates[index].empty()) continue;
		int value = plates[index].front();
		plates[index].pop();
		int score = value + plates_score(max, depth + 1, num, i, plates);
		if (score > maxScore) maxScore = score;
	}

	cout << "Score : " << maxScore << endl;
	return maxScore;

}


int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int N, K, P;
		cin >> N >> K >> P;

		vector<queue<int>> plates;

		plates.resize(N);
		for (int n = 0; n < N; n++) {
			for (int k = 0; k < K; k++) {
				int val;
				cin >> val;
				plates[n].push(val);
			}
		}
		
		int maxScore = 0;
		for (int i = 0; i < N; i++) {
			int score = plates_score(P, 0, N, i, plates);
			if (score > maxScore) maxScore = score;
			cout << "Loop = " << i << "    - Score = " << score << endl;
		}

		cout << "Case #" << t+1 << ": " << maxScore << endl;

	}	

	return 0;

}