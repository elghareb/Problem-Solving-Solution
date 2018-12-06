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
ll power(ll a, ll p) {
	if (p == 0) {
		return 1;
	}
	ll ans = power(a, p / 2);

	if (p % 2 == 0) {
		return ans * ans;
	} else {
		return a * ans * ans;
	}
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	ll ans;
	vector<int> v;
	int t, n;
	cin >> t;
	while (t--) {
		ans = 0;
		v.clear();
		while (cin >> n && n) {
			v.push_back(n);
		}

		sort(ALL(v), greater<int>());
		for (int i = 0; i < SZ(v); ++i) {
			ans += power(v[i], i + 1) * 2;
			if (ans > 5000000) {
				break;
			}
		}
		if (ans > 5000000) {
			cout << "Too expensive" << endl;
		} else
			cout << ans << endl;
	}

	return 0;

}

