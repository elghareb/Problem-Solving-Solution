#include <bits/stdc++.h>
#define SZ(s) ((int)s.size())
using namespace std;

int arr[21];
int length;
int n;
bool c() {
	int sum;

	for (int i = 0; i < (1 << n); ++i) {
		sum = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				sum += arr[j];
			}
		}
		if (sum == length) {
			return true;
		}
	}
	return false;

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> length >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		if (c()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}


