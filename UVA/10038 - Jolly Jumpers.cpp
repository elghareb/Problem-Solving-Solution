#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

int arr[3010];
int main() {
	bitset<3001> x;
	x = 0;
	int n, z;
	while (cin >> n) {
		x = 0;
		z = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		for (int i = 1; i < n; ++i) {
			z = abs(arr[i] - arr[i - 1]);
			x.set(z);
		}
		z = 0;
		for (int i = 1; i < n; ++i) {
			if (x[i]) {
				z++;
			}
		}
		if (z == n - 1) {
			cout << "Jolly" << endl;
		} else {
			cout << "Not jolly" << endl;
		}

	}
	return 0;
}

