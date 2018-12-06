#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>

#define clr(a,b) memset(a,b,sizeof a)
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	bool row[10010];
	bool col[10010];
	int n, c, r, x, y;

	int C = 0;
	while (cin >> r >> c >> n && r) {
		clr(row, 1);
		clr(col, 1);
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			row[x] = 0;
			col[y] = 0;
		}
		cin >> x >> y;

		bool ans = false;
		if (row[x] && col[y]) {
			ans = 1;
		}
		if (x - 1 >= 0) {
			if (row[x - 1] && col[y]) {
				ans = 1;
			}
		}
		if (x + 1 < r) {
			if (row[x + 1] && col[y]) {
				ans = 1;
			}
		}
		if (y - 1 >= 0) {
			if (row[x] && col[y - 1]) {
				ans = 1;
			}
		}
		if (x + 1 < c) {
			if (row[x] && col[y + 1]) {
				ans = 1;
			}
		}
//		for (int i = 0; i < r; ++i) {
//			for (int j = 0; j < c; ++j) {
//				cout <<( row[i] && col[j]) << " ";
//			}
//			cout << endl;
//		}
		cout << "Case " << ++C << ": ";
		if (ans) {
			cout << "Escaped again! More 2D grid problems!\n";
		} else {
			cout << "Party time! Let's find a restaurant!\n";
		}

	}

	return 0;

}

