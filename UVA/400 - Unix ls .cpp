#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
string arr[101];
int mx = 0;

void print(int n) {
	cout << "------------------------------------------------------------"
			<< endl;

	sort(arr, arr + n);
	int c = 62 / mx;
	int all = ceil(1.0 * n / c);

	for (int i = 0; i < all; i += 1) {
		int j = i;
		for (; j < n - all; j += all) {
			cout << arr[j];
			int m = SZ(arr[j]);
			for (int k = 0; k < mx - m; ++k) {
				cout << " ";
			}
		}
		cout << arr[j] << endl;

	}
}
int main() {
	int n;
	while (cin >> n) {
		mx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			mx = max(mx, (int) arr[i].size() + 2);
		}
		print(n);
		mx = 0;
	}

	return 0;
}

