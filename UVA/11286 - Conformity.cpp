#include <bits/stdc++.h>
using namespace std;

int main() {

	map<set<int>, int> m;
	map<set<int>, int>::iterator it;

	set<int> s;
	int n, x, mx;
	int c = 0;
	while (cin >> n && n != 0) {
		mx = 1;
		c = 0;
		for (int i = 0; i < n; ++i) {
			for (int i = 0; i < 5; ++i) {
				cin >> x;
				s.insert(x);
			}
			////////////////////////////////
			if (m.find(s) != m.end()) {
				m[s]++;
				mx = max(mx, m[s]);
			} else {
				m[s] = 1;
			}
			////////////////////////////////
			s.clear();
		}
		for (it = m.begin(); it != m.end(); ++it) {
			if (it->second == mx) {
				c++;
			}
		}

		cout << mx * c << endl;
		m.clear();

	}
	return 0;
}

