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

vector<ll> primes;

bool pm[1000002];
void sieve(ll upperbound) {

	memset(pm, 1, sizeof pm);
	pm[0] = pm[1] = 0;
	for (ll i = 2; i <= upperbound; i++) {
		if (pm[i]) {
			for (ll j = i * i; j <= upperbound; j += i)
				pm[j] = 0;
			primes.push_back((int) i);
		}
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	sieve(1000002);

	int x;
	while (cin >> x && x) {
		for (int i = 0; i <= SZ(primes); ++i) {
			int p = primes[i];
			if (pm[x - p]) {
				cout<<x<<" = ";
				cout << p << " + " << x - p << endl;
				break;
			}
		}

	}
	return 0;
}

