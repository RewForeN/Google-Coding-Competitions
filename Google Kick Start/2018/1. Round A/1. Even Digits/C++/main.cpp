
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;
using ll = long;


bool even_digits(string s) {
	for (char c : s) {
		ll v = (c - '0');
		if (v % 2 != 0) return false;
	}
	return true;
}

ll up(string s, ll original) {

	ll n = stol(s);

	while (!even_digits(s)) {

		ll index;
		ll num_zeros = 0;
		bool b = false;
		for (ll i = 0; i < s.length(); i++) {
			ll v = (s[i] - '0');
			if (b) {
				s[i] = '0';
				num_zeros++;
			}
			else if (v % 2 != 0) {
				index = i;
				b = true;
			}
		}

		n = stol(s);
		if (b) n += pow(10, num_zeros);
		s = to_string(n);

	}

	return n - original;

}

ll down(string s, ll original) {

	ll num_zeros = 0;
	bool b = false;
	for (ll i = 0; i < s.length(); i++) {
		ll v = (s[i] - '0');
		if (b) {
			s[i] = '8';
			num_zeros++;
		}
		else if (v % 2 != 0) {
			b = true;
		}
	}

	ll n = stol(s);
	if (b) n -= pow(10, num_zeros);
	s = to_string(n);

	return original - n;

}


int main() {

	ll T;
	cin >> T;

	for (ll t = 0; t < T; t++) {

		string s, s_up, s_down;
		cin >> s;

		ll _min = min(up(s, stol(s)), down(s, stol(s)));

		cout << "Case #" << t+1 << ": " << _min << endl;

	}

	return 0;

}