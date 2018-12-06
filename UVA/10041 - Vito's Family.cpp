#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int main() {
//		freopen("in.txt", "rt", stdin);

	int arr[510];
	int n, r, sum, mn;

	scanf("%d", &n);
	while (n--) {
		sum = 0;
		mn = 500 * 30000;
		scanf("%d", &r);
		for (int i = 0; i < r; ++i) {
			cin >> arr[i];
		}

		for (int i = 0; i < r; ++i) {
			sum = 0;
			for (int j = 0; j < r; ++j) {
				sum += abs(arr[i] - arr[j]);
			}
			mn = min(sum, mn);
		}

		cout << mn << endl;
	}

	return 0;
}

