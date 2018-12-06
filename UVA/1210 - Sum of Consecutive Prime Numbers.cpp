#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

bool pm[10010];
vector<ll> primes;

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
//	freopen("output.txt", "w", stdout);
#endif

	map<int, int> m;
	sieve(10010);
	int sum = 0;

	for (int i = 0; i < SZ(primes); ++i) {
		sum = 0;
		for (int j = i; j < SZ(primes); ++j) {
			sum += primes[j];
			m[sum]++;
		}

	}
	int n;
	while (cin >> n && n) {
		cout << m[n] << endl;
	}

	return 0;
}

