#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
using namespace std;

int main() {

	long long cow[100010];
	int n, k;

	int t = 0;
	cin>>t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> cow[i];
		}
		sort(cow, cow + n);
		int lo = 0;
		int hi = cow[n - 1];

		while (hi > lo) {
			int dis = lo + (hi - lo) / 2;
			/////
			long long last = cow[0];
			int c = 1;
			for (int i = 1; i < n; ++i) {
				if (cow[i] - last >= dis) {
					c++;
					last = cow[i];
				}
			}
			////
			if (c >= k) {
				lo = dis + 1;
			} else {
				hi = dis;
			}
		}
		cout << lo - 1 << endl;
	}
	return 0;
}

