#include <bits/stdc++.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

bool so(pair<double, double> &f1, pair<double, double> &f2) {
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

	vector<pair<double, double>> v;
	int n, l, w;
	double x, r;

	while (cin >> n >> l >> w) {

		v.clear();
		for (int i = 0; i < n; ++i) {
			cin >> x >> r;
			if (r > w / 2.0) {
				double dx = sqrt((r * r) - w * w / 4.0);
				v.push_back( { x - dx, x + dx });
			}
		}
		sort(ALL(v), so);
		int ans = 0;

		double mxRight = 0;
		double canReachTo = 0;

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
			ans = -1;
		}

		cout << ans << endl;
	}
	return 0;

}

