#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

int main() {

	map<char, char> m;
	m['B'] = '1';
	m['F'] = '1';
	m['P'] = '1';
	m['V'] = '1';
	/////////////////////
	m['C'] = '2';
	m['G'] = '2';
	m['J'] = '2';
	m['K'] = '2';
	m['Q'] = '2';
	m['S'] = '2';
	m['X'] = '2';
	m['Z'] = '2';
	////////////////////
	m['D'] = '3';
	m['T'] = '3';
	///////////////////////
	m['L'] = '4';
	m['M'] = '5';
	m['N'] = '5';
	m['R'] = '6';
	//////////////////////
	string a = "";
	string b;
	char c = ' ';
	while (cin >> b) {
		c = ' ';
		for (int i = 0; i < SZ(b); ++i) {
			if ((int) m.count(b[i])) {

				if (m[b[i]] == c) {
//					cout << i << endl;
					continue;
				}

				a += m[b[i]];
				c = m[b[i]];
			} else {
				c = ' ';
			}
		}
		cout << a << endl;
		a = "";
	}

	return 0;
}

