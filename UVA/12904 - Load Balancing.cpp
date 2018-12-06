#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int a[161];

	int t = 0;
	int T, n, x;
	cin >> T;
	while (T--) {
		clr(a, 0);
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			a[x]++;
		}

		for (int i = 1; i <= 160; ++i) {
			a[i] += a[i - 1];
		}
		int A, B, C;
		int d = 0;
		ll mn = LONG_LONG_MAX;

		for (int x1 = 0; x1 <= 160; ++x1) {
			for (int x2 = x1 + 1; x2 <= 160; ++x2) {
				for (int x3 = x2 + 1; x3 <= 160; ++x3) {
					int G1 = a[x1];
					int G2 = a[x2] - a[x1];
					int G3 = a[x3] - a[x2];
					int G4 = a[160] - a[x3];
					d = abs(4 * G1 - n) + abs(4 * G2 - n) + abs(4 * G3 - n)
							+ abs(4 * G4 - n);
					if (d < mn) {
						mn = d;
						A = x1;
						B = x2;
						C = x3;
					}

				}
			}
		}
//		cout<<mn<<endl;

		cout << "Case " << ++t << ": ";
		cout << A << " " << B << " " << C << endl;

	}

	return 0;
}

