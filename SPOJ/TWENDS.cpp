#include <bits/stdc++.h>
#define SZ(s) ((int)s.size())
using namespace std;

int  arr[1001];
int memo[1001][1001];

int dp(int i, int j) {
	if (i > j) {
		return 0;
	}
	int &ans = memo[i][j];
	if (ans != -1) {
		return ans;
	}
	// first choose
	int c1 = arr[i];
	if (arr[i + 1] >=arr[j]) {
		c1 += dp(i + 2, j);
	} else {
		c1 += dp(i + 1, j - 1);
	}
	// second choose
	int c2 = arr[j];
	if (arr[i] >=arr[j - 1]) {
		c2 += dp(i + 1, j - 1);
	} else {
		c2 += dp(i, j - 2);
	}
	return ans = max(c1, c2);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;

	int i = 0;
	while (cin >> n) {
		if(n==0){
			break;
		}
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int sum = accumulate(arr, arr + n, 0);
		int first = dp(0, n - 1);

		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++i,(2 * first - sum) );

	}
	return 0;
}

