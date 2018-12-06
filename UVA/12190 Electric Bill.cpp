#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>
#define clr(a,b) memset(a,b,sizeof a)
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;

ll calc(ll x) {
	ll c = 2 * min(100LL, x);
	c += 3 * min(10000 - 100LL, max(x - 100, 0 * 1LL));
	c += 5 * min(1000000 - 10000LL, max(x - 10000, 0 * 1LL));
	c += 7 * max(0LL, x - 1000000);
	return c;
}
ll A, B, x, y;

//  x + y  = A ;
// |x - y| = B ;

void X() {

	ll lo = 0;
	ll hi = 1e10;
	ll mid, c;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		c = calc(mid);
		if (c >= A) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}

	x = lo;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	while (cin >> A >> B) {
		if (A == 0 && B == 0) {
			break;
		}
		X();
		ll lo = 0;
		ll hi = x / 2;
		ll mid, c1, c2;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;
			c1 = calc(mid);
			c2 = calc(x - mid);

			if (c2 - c1 <= B) {
				hi = mid;
			} else {
				lo = mid + 1;

			}
		}
		cout << calc(lo) << endl;
	}

	return 0;

}

