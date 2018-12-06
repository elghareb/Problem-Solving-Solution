#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)
///////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;
///////////////////////////////////////
const double EPS = (1e-8);
const double PI = acos(-1);
///////////////////////////////////////

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	vector<pair<ll, char>> v;
	int n, m, x;
	int t;
	ll ans = 0;

	cin >> t;
	while (t--) {
		v.clear();
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i < n - 1; ++i) {
			cin >> x;
			v.push_back( { x, 'h' });
		}

		for (int i = 0; i < m - 1; ++i) {
			cin >> x;
			v.push_back( { x, 'v' });
		}

		sort(ALL(v));
		reverse(ALL(v));

		ll H = 1;
		ll V = 1;
		for (int i = 0; i < SZ(v); ++i) {
			if (v[i].second == 'h') {
				H++;
				ans += V * v[i].first;
			} else {
				V++;
				ans += H * v[i].first;
			}
		}
		cout << ans << endl;

	}

	return 0;
}
