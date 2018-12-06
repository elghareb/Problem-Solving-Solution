#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>

#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define clr(a,b) memset(a,b,sizeof a)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	ll acc[101];
	ll c =0;
	for (int i = 0; i <= 99; i += 1) {
		if (i % 2 != 0)
			c += i;
		acc[i]=c;
	}
	int t, a, b;
	cin >> t;
	c = 0;
	while (t--) {
		cin >> a >> b;
		if (a % 2 == 0) {
			a++;
		}
		if (b % 2 == 0) {
			b--;
		}
		cout << "Case " << ++c << ": ";
		cout << acc[b]-acc[a-1]<< endl;
	}

	return 0;
}

