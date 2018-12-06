#include <bits/stdc++.h>
#include <numeric>      // std::iota

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

int a[1500], n, t, m;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> t >> m;
		int time = 0;
		for (int i = 0; i < m; ++i) {
			cin >> a[i];
		}
		sort(a, a + m);

		int pos = 0;
		if (m % n) {
			pos = m % n;
		} else {
			pos = n;
		}
		int numofTrip = (m + n - 1) / n;
		for (int i = pos - 1; i < m; i += n) {
			time = max(time, a[i]) + 2 * t;
		}
		cout << time - t << " " << numofTrip << endl;
	}
	return 0;

}

