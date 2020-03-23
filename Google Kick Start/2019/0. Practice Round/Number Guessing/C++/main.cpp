
#include <iostream>
#include <string>

using namespace std;


int main() {

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {

    int A, B;
    cin >> A >> B;

    int N;
    cin >> N;

    int low = A + 1, high = B;

    while (true) {

      int Q = (low + high) / 2;
      cout << Q << endl;

      string s;
      cin >> s;
      if (s == "CORRECT") break;
      if (s == "TOO_SMALL") low = Q + 1;
      if (s == "TOO_BIG") high = Q - 1;
	  else cerr << "INCORRECT_ANSWER" << endl;

    }

  }

  return 0;

}
