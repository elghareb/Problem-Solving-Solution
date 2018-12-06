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
////	freopen("output.txt", "w", stdout);
#endif
//	ios_base::sync_with_stdio(false);

	int r[20], g[20], b[20];

	for (int i = 0; i < 16; ++i) {
		scanf("%d %d %d", &r[i], &g[i], &b[i]);
	}

	int R, G, B;

	while (true) {
		scanf("%d %d %d", &R, &G, &B);
		if (R == -1 && G == -1 && B == -1) {
			break;
		}
		ll ans = -1;
		ll mn = 0;
		for (int i = 0; i < 16; ++i) {
			ll rr = (R - r[i]) * (R - r[i]);
			ll gg = (G - g[i]) * (G - g[i]);
			ll bb = (B - b[i]) * (B - b[i]);

			ll dis = (rr + gg + bb);
			if (ans == -1 || mn > dis) {
				mn = dis;
				ans = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", R, G, B, r[ans], g[ans],
				b[ans]);

	}

	return 0;
}

