
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class MuralWall {

private:
	int m_num_scores = 0;
	int m_last_painted_left = -1;
	int m_last_painted_right = -1;
	int m_last_degraded_left = -1;
	int m_last_degraded_right = -1;
	vector<int> m_beauty_scores;
	vector<int> m_moves;

public:
	MuralWall(int num_scores, vector<int> beauty_scores) {
		m_num_scores = num_scores;
		m_beauty_scores = beauty_scores;
	}
	void first_move(int index) {
		m_moves.resize(m_num_scores);
		for (int i = 0; i < m_num_scores; i++) m_moves[i] = 0;
		m_moves[index] = 1;
		m_last_painted_left = index;
		m_last_painted_right = index;
		m_last_degraded_right = m_num_scores;
	}
	bool paint_left() {
		int i = m_last_painted_left - 1;
		if (m_moves[i] == 0)
	}
	bool paint_right() {
		if (m_paintable_right != -1) m_moves[m_paintable_right] = 1;
		else return false;
		return true;
	}
	bool degrade_left() {
		if (m_degradable_left != -1) m_moves[m_degradable_left] = -1;
		else return false;
		return true;
	}
	bool degrade_right() {
		if (m_degradable_right != -1) m_moves[m_degradable_right] = -1;
		else return false;
		return true;
	}
	MuralWall copy() {

	}

	friend int main();

};


int mural(bool moveToLeft, int depth, bool isMaximizing, MuralWall wall) {



	isMaximizing = !isMaximizing;

	if (isMaximizing) {

		int score = max(mural(), mural());

	}
	else {

		int score = min();

	}

}


int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int N;
		cin >> N;

		string s;
		cin >> s;

		vector<int> beauty_scores(N);

		for (int i = 0; i < N; i++) {
			int val = s[i];
			beauty_scores.push_back(val);
		}

		MuralWall muralWall(N, beauty_scores);

		int maxScore = 0;
		for (int i = 0; i < N; i++) {
			MuralWall wall = muralWall.copy();
			wall.first_move(i);
			maxScore = wall.m_beauty_scores[i] + max(mural(true, 0, false, wall), mural(false, 0, false, wall));
		}

		cout << maxScore << endl;

	}

	return 0;

}