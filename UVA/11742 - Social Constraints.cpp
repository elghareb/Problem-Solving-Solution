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

	int a[21], b[21], c[21];
	vector<int> teen;
	int n, m;

	while (cin >> n >> m && (n + m != 0)) {
		teen.clear();
		for (int i = 0; i < n; ++i) {
			teen.push_back(i);
		}
		for (int i = 0; i < m; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		int ans = 0;

		do {
			int cc = 0;
			for (int i = 0; i < m; ++i) {
				if (c[i] > 0) {
					if (abs(teen[a[i]] - teen[b[i]]) > c[i]) {
						cc++;
					}
				} else {
					if (abs(teen[a[i]] - teen[b[i]]) < (-1 * c[i])) {
						cc++;
					}
				}
			}
			if (!cc) {
				ans++;
			}
		} while (next_permutation(ALL(teen)));
		cout << ans << endl;
	}
	return 0;
}

