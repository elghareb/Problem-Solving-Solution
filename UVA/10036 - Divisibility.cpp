#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>

#define clr(a,b) memset(a,b,sizeof a)
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int a[10010];
	bool dp[10010][110];

	int n, k, t;
	cin >> t;

	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] = ((a[i] % k) + k) % k;
		}
		memset(dp, 0, sizeof dp);
		dp[0][0] = true;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				if (dp[i][j]) {
					int add = (j + a[i] + k) % k;
					int sub = (j - a[i] + k) % k;

					dp[i + 1][add] = true;
					dp[i + 1][sub] = true;
				}
			}
		}
		cout << ((dp[n][0] == 1) ? "Divisible\n" : "Not divisible\n");

	}

	return 0;

}

