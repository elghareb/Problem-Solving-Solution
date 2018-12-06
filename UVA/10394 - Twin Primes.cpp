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


bool pm[18409202];
void sieve(ll upperbound) {
	vector<ll> primes;
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
	sieve(18409202);
	vector<pair<int,int>>p;
	p.push_back({0,0});
	int c = 0;
	for (int i = 2; i < 18409202; ++i) {
		if(pm[i]&&pm[i+2]){
			p.push_back( { i, i + 2 });
		}
	}
	int x;
	while(cin>>x){
		cout << "(" << p[x].first << ", " << p[x].second << ")\n";
	}



	return 0;
}

