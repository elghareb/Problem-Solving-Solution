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
int dp[100];
set<pair<pair<int, int>, int>> s;
vector<pair<pair<int, int>, int>> v(ALL(s));

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int n, t, x, y, z;
	t = 0;
	while (cin >> n && n) {
		t++;
		s.clear();
		v.clear();
		for (int i = 0; i < n; ++i) {
			cin >> x >> y >> z;
			s.insert( { { max(y, z), min(y, z) }, x });
			s.insert( { { max(x, z), min(x, z) }, y });
			s.insert( { { max(y, x), min(y, x) }, z });
		}
		// sort by base larger
		v.assign(ALL(s));
		sort(ALL(v), greater<pair<pair<int, int>, int>>());
		for (int i = 0; i < SZ(v); ++i) {
			dp[i] = v[i].second;
		}
		int ans = 0;
		for (int i = 0; i < SZ(v) - 1; ++i) {
			for (int j = i + 1; j < SZ(v); ++j) {
				if (v[i].first.first > v[j].first.first
						&& v[i].first.second > v[j].first.second) {
					dp[j] = max(dp[i] + v[j].second, dp[j]);
				}

				ans = max(ans, dp[j]);
			}
		}
		cout << "Case " << t << ": maximum height = ";
		cout << ans << endl;
	}
	return 0;
}

