#include <bits/stdc++.h>
#include <unordered_map>
#include <functional>

#define SZ(s) ((int)s.size())
#define ALL(s) s.begin(),s.end()
#define FOR(i,n) for (int i = 0; i < n; ++i)

using namespace std;
long long p;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, c;
	while (cin >> n >> m >> c) {
		if (n == 0) {
			break;
		}
		n = n - 7;
		m = m - 7;

		int n1 = n / 2;
		int n2 = n / 2;
		if (n % 2 != 0) {
			if (c) {
				n1++;
			} else {
				n2++;
			}
		}

		int m1 = m / 2;
		int m2 = m / 2;

		if (m % 2 != 0) {
			if (c) {
				m1++;
			} else {
				m2++;
			}
		}
		int ans = 0;
		if (c) {
			ans = n1 * m1 + n2 * m2;
		} else {
			ans = n1 * m2 + n2 * m1;
		}
		cout << ans << endl;
	}
	return 0;
}

