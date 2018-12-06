#include <bits/stdc++.h>
#include <unordered_map>
#include <functional>

#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()
using namespace std;
typedef long long ll;

ll LCM(ll a, ll b) {
	return max(a, b) / __gcd(a, b) * min(a, b);
}

int dp[1001][1001];

string s;
int solve(int i, int j) {
	if (i >= j) {
		return 0;
	}
	int &ret = dp[i][j];
	if (ret != -1) {
		return ret;
	}
	if (s[i] == s[j]) {
		ret = solve(i + 1, j - 1);
	}
	if (s[i] != s[j]) {
		ret = 1 + min(solve(i + 1, j), solve(i, j - 1));
	}
	return ret;
}
string ans;
void dp1(int i, int j) {
	if (i > j) {
		return;
	}
	if (s[i] == s[j]) {
		ans.push_back(s[i]);
		dp1(i + 1, j - 1);
		if (i != j)
			ans.push_back(s[j]);
	} else {
		if (solve(i, j) == solve(i + 1, j) + 1) {
			ans.push_back(s[i]);
			dp1(i + 1, j);
			ans.push_back(s[i]);
		} else if (solve(i, j) == solve(i, j - 1) + 1) {
			ans.push_back(s[j]);
			dp1(i, j - 1);
			ans.push_back(s[j]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> s) {
		memset(dp, -1, sizeof dp);
		cout << solve(0, SZ(s) - 1) << " ";
		dp1(0, SZ(s) - 1);
		cout << ans << endl;
		ans.clear();
	}
	return 0;

}
