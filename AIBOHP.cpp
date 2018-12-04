#include <bits/stdc++.h>
#include <unordered_map>
#include <functional>

#define SZ(s) ((int)s.size())
#define ALL(s) s.begin(),s.end()

using namespace std;

string s;
int memo[6200][6200];
int dp(int i, int j) {
	if (i >= j) {
		return 0;
	}

	int &ans = memo[i][j];
	if (ans != -1) {
		return ans;
	}
	if (s[i] == s[j]) {
		ans = dp(i + 1, j - 1);
	} else {
		int c1 = 1 + dp(i + 1, j);
		int c2 = 1 + dp(i, j - 1);
		ans = min(c1, c2);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(memo,-1,sizeof memo);
		cin >> s;
		cout << dp(0, SZ(s) - 1)<<endl;
	}
	return 0;
}
