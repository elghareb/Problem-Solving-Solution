#include <bits/stdc++.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

bool so(pair<int, int> &f1, pair<int, int> &f2) {
	if (f1.first < f2.first) {
		return true;
	}
	if (f1.first == f2.first) {
		return f1.second > f2.second;
	}
	return false;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	vector<pair<int, int>> v;
	int n, l, x, r;
	while (cin >> l >> n && n && l) {

		v.clear();
		for (int i = 0; i < n; ++i) {
			cin >> x >> r;
			v.push_back( { x - r, x + r });
		}
		sort(ALL(v), so);
		int ans = 0;

		int mxRight = 0;
		int canReachTo = 0;
		for (int i = 0; i < SZ(v) && mxRight < l;) {
			while (i < SZ(v) && mxRight >= v[i].first) {
				canReachTo = max(canReachTo, v[i].second);
				i++;
			}
			if (canReachTo > mxRight) {
				ans++;
				mxRight = canReachTo;
			} else {
				break;
			}
		}
		if (mxRight < l) {
			cout << -1 << endl;
		} else
			cout << n - ans << endl;
	}
	return 0;

}

