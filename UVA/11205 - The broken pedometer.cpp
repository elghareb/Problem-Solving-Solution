#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int x[100];

	int t, z;
	int p, n;
	cin >> t;

	while (t--) {
		memset(x, 0, sizeof x);

		cin >> p >> n;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < p; ++j) {
				cin >> z;
				x[i] = x[i] | (z << j);
			}
		}
		set<int> s;
		int mask = 0;
		int mn = p;
		for (int i = 0; i < (1 << p); ++i) {
			s.clear();
			mask = 0;
			for (int j = 0; j < p; ++j) {
				mask |= (i & (1 << j));
			}
			int c = bitset<16>(i).count();
			for (int k = 0; k < n; ++k) {
				s.insert(mask & x[k]);
			}
			if (SZ(s) == n) {
				mn = min(mn, c);
			}
		}
		cout << mn << endl;
	}
	return 0;
}


