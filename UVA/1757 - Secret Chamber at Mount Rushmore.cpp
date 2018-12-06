#include <bits/stdc++.h>
#include <unordered_map>
#include <time.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

vector<int> v[100];
bool vis[100];
bool dfs(int s, int e) {

	if (s == e) {
		return true;
	}
	vis[s] = 1;
	bool ans = 0;
	for (int i = 0; i < SZ(v[s]); ++i) {
		int c = v[s][i];
		if (!vis[c] && !ans) {
			ans |= dfs(c, e);
		}
	}
	return ans;
}
bool eq(string s1, string s2) {

	if (SZ(s1) != SZ(s2)) {
		return false;
	}
	for (int i = 0; i < SZ(s1); ++i) {
		int x = s1[i] - 'a';
		int y = s2[i] - 'a';
		clr(vis, 0);

		if (!dfs(x, y)) {
			return false;
		}
	}
	return true;
}
int main() {

#ifndef ONLINE_JUDGE
	clock_t start = clock();
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	int n, m;
	char x, y;
	string s1, s2;

	while (cin >> m >> n) {
		for (int i = 0; i < 30; ++i) {
			v[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			v[x - 'a'].push_back(y - 'a');
		}
		for (int i = 0; i < n; ++i) {
			cin >> s1 >> s2;
			if (eq(s1, s2)) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
	}

#ifndef ONLINE_JUDGE
	clock_t stop = clock();
	double elapsed_secs = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Time elapsed in s :" << elapsed_secs << endl;
#endif
	return 0;
}

