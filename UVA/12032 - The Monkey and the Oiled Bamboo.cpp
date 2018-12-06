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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int arr[100010];
	int T, n;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		arr[0] = 0;
		ll lo = 1;
		ll hi = 1e8;
		ll k;

		while (lo < hi) {
			k = lo + (hi - lo) / 2;
			for (int i = 1; i<=n; ++i) {
				if (arr[i] - arr[i - 1] > k) {
					k = -10000;
					break;
				} else if (arr[i] - arr[i - 1] == k) {
					k--;
				}
			}
			if (k >= 0) {
				hi = lo + (hi - lo) / 2;
			} else {
				lo = (lo + (hi - lo) / 2) + 1;
			}

		}
		cout << "Case " << t + 1 << ": " << hi << endl;
	}
	return 0;
}

