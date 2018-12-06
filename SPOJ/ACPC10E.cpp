#include <bits/stdc++.h>
#include <unordered_map>
#include <time.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

ll f(ll n) {
	ll m = 1;
	while (m < n)
		m *= 2;
	return m; // smallest pow of 2, greater than or equal to n
}
int main() {

#ifndef ONLINE_JUDGE
	clock_t start = clock();
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

//	ull x = (1 << 16)*(1 << 16)*(1 << 16);
//	cout << x << endl;

	vector<ll> po;
	for (int i = 0; i <= 63; ++i) {
		po.push_back(1LL << i);
	}
	ll G, T, A, D;

	while (cin >> G >> T >> A >> D && G != -1) {

		ll Game = (T * (T - 1) / 2) * G;

		ll advancedTeam = (G * A) + D;

		ll TeamS = *lower_bound(ALL(po), advancedTeam);
		ll added = (TeamS - advancedTeam);

		Game += TeamS - 1;
		cout << G << "*" << A << "/" << T << "+" << D << "=";
		cout << Game << "+" << added << endl;

	}
#ifndef ONLINE_JUDGE
	clock_t stop = clock();
	double elapsed_secs = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Time elapsed in s :" << elapsed_secs << endl;
#endif
	return 0;
}
