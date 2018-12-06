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
	int dp[10010];
	int n, m, t;

	while (cin >> n >> m >> t) {
		clr(dp, -1);
		dp[0] = 0;

		for (int i = 1; i <= t; ++i) {
			if (i - n >= 0 && dp[i - n] != -1) {
				dp[i] = 1 + dp[i - n];
			}
			if (i - m >= 0 && dp[i - m] != -1) {
				dp[i] = max(dp[i], 1 + dp[i - m]);
			}
		}


		if (dp[t] != -1) {
			cout << dp[t] << endl;
		} else {
			for (int i = t; i >=0; --i) {
				if (dp[i] != -1) {
					cout << dp[i] << " " << t - i << endl;
					break;
				}
			}
		}
	}
	return 0;

}

