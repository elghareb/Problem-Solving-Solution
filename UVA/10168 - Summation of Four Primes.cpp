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

bool pm[10000005];
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
	sieve(10000003);

	int x;
	while (cin >> x) {
		if (x <= 7) {
			cout << "Impossible." << endl;
		} else if (x % 2 == 0) {
			cout << "2 2 ";
			x -= 4;
			for (int i = 2; i < 10000000; i++) {
				if (pm[i] && pm[x - i]) {
					cout << i << " " << x - i << endl;
					break;
				}
			}

		} else {
			cout << "2 3 ";
			x -= 5;
			for (int i = 2; i < 10000000; i++) {
				if (pm[i] && pm[x - i]) {
					cout << i << " " << x - i << endl;
					break;
				}
			}
		}

	}
	return 0;
}

