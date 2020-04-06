
/*
 * By: 			Ruan Swanepoel
 * Completed: 	5/04/2020
 */

#include <iostream>
#include <vector>

using namespace std;


bool vec_find(vector<int> vec, int key) {

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == key) {
			return true;
		}
	}

	return false;

}


int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		vector<vector<int>> matrix;

		int N;
		cin >> N;

		matrix.resize(N, vector<int>(N));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> matrix[i][j];
			}
		}

		// Trace
		int k = 0;
		for (int i = 0; i < matrix.size(); i++) {
			k += matrix[i][i];
		}

		// Rows
		int r = 0;
		for (int i = 0; i < matrix.size(); i++) {
			vector<int> rows(N);
			for (int j = 0; j < matrix.size(); j++) {
				if (vec_find(rows, matrix[i][j])) {
					r++;
					break;
				}
				rows.push_back(matrix[i][j]);
			}
		}

		// Cols
		int c = 0;
		for (int i = 0; i < matrix.size(); i++) {
		vector<int> cols(N);
			for (int j = 0; j < matrix.size(); j++) {
				if (vec_find(cols, matrix[j][i])) {
					c++;
					break;
				}
				cols.push_back(matrix[j][i]);
			}
		}

		cout << "Case #" << t+1 << ": " << k << " " << r << " " << c << endl;

	}

	return 0;

}