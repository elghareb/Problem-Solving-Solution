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
int c;
int a[101];
int p[101];
int dp[105][105];

int solve(int i, int last) {
	if (i == c + 1) {
		if (i != last) {
			return 1e9;
		}
		return 0;
	}
	int &ret = dp[i][last];
	if (ret != -1) {
		return ret;
	}

	int sum = (a[i] - a[last - 1]) + 10;

	int c1 = solve(i + 1, i + 1) + sum * p[i];
	int c2 = solve(i + 1, last);

	return ret = min(c1, c2);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		clr(dp, -1);

		cin >> c;

		a[0] = 0;
		for (int i = 1; i <= c; ++i) {
			cin >> a[i] >> p[i];
			a[i] += a[i - 1];
		}
		cout << solve(1, 1)<<endl;
	}
	return 0;

}

