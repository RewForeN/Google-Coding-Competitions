
/*
 * By: 			Ruan Swanepoel
 * Completed: 	5/04/2020
 */

#include <iostream>
#include <vector>

using namespace std;


struct Task {
	int s;
	int e;
};


bool contains(vector<int> order, int j) {
	for (int i = 0; i < order.size(); i++) {
		if (order[i] == j) return true;
	}
	return false;
}


int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int N;
		cin >> N;

		// Read values
		vector<Task> tasks;
		for (int n = 0; n < N; n++) {
			Task task;
			cin >> task.s >> task.e;
			tasks.push_back(task);
		}

		// Order in terms of start time
		vector<int> order(N);
		for (int i = 0; i < N; i++) { order[i] = -1; }

		for (int i = 0; i < N; i++) {
			pair<int, int> min(-1, 999999);
			for (int j = 0; j < N; j++) {
				if (tasks[j].s < min.second  &&  !contains(order, j)) {
					min.first = j;
					min.second = tasks[j].s;
				}
			}
			order[i] = min.first;
		}

		// Generate task delegation
		int C_end = 0;
		int J_end = 0;

		vector<string> v(N);
		bool isImpossible = false;

		for (int i = 0; i < N; i++) {
			int index = order[i];
			if (tasks[index].s >= C_end) {
				C_end = tasks[index].e;
				v[index] = "C";
			}
			else if (tasks[index].s >= J_end) {
				J_end = tasks[index].e;
				v[index] = "J";
			}
			else {
				isImpossible = true;
				break;
			}
		}

		// Vector to string
		string result = "";
		if (isImpossible) {
			result = "IMPOSSIBLE";
		}
		else {
			for (int i = 0; i < N; i++) {
				result += v[i];
			}
		}

		cout << "Case #" << t+1 << ": " << result << endl;

	}

	return 0;
	
}