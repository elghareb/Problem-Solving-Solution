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

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	ll c, n, x, y, z, k, ans;

	cin >> c;
	while (c--) {
		ans = 500 * 500;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n/i; ++j) {
				if (n % (i * j) == 0) {
					k = n / (i * j);
					x = i * k;
					y = j * k;
					z = i * j;
					ans = min(ans, 2 * (x + y + z));
				}

			}
		}
		cout << ans << endl;
	}

	return 0;
}

