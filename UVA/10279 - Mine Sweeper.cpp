#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>

#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define clr(a,b) memset(a,b,sizeof a)
#define fr first
#define sc second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	string s[15];
	string ss[15];
	int cnt[15][15];
	int t;
	int n;
	cin >> t;
	int z = 0;

	while (t--) {
		if (z != 0) {
			cout << endl;
		}
		z++;
		cin >> n;
		clr(cnt, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> s[i];
			s[i] = " " + s[i];
			for (int j = 1; j <= n; ++j) {
				if (s[i][j] == '*') {
					for (int d = 0; d < 8; ++d) {
						int nx = i + dx[d];
						int ny = j + dy[d];
						cnt[nx][ny]++;
					}
				}
			}
		}

		bool touched = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> ss[i];
			ss[i] = " " + ss[i];
			for (int j = 1; j <= n; ++j) {
				if (ss[i][j] == 'x' && s[i][j] == '*') {
					touched = 1;
					break;
				}
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (ss[i][j] == 'x') {
					if (s[i][j] == '.') {
						cout << cnt[i][j];
					} else if (s[i][j] == '*' && touched) {
						cout << s[i][j];
					} else {
						cout << '.';
					}
				} else {
					if (touched) {
						cout << s[i][j];
					} else {
						cout << ".";
					}
				}
			}
			cout << endl;
		}

	}

	return 0;
}

