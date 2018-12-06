#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;
int n, m;
int arr[1010];
int matrix[1010];
int abs(int x) {
	if (x >= 0) {
		return x;
	} else {
		return -x;
	}
}
int fi(int x) {
	int mn = 1 << 30;
	int closet = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
//			cout << (arr[i] + arr[j]) << " ";
			if (abs(x - (arr[i] + arr[j])) < mn) {
				mn = abs(x - (arr[i] + arr[j]));
				closet = (arr[i] + arr[j]);
			}
		}
//		cout << endl;
	}
	return closet;
}

int main() {
	ios_base::sync_with_stdio(0);
	int x;
	int j = 1;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cin >> m;
		cout << "Case " << j++ << ":" << endl;
		for (int i = 0; i < m; ++i) {
			cin >> x;
			cout << "Closest sum to " << x << " ";
			cout << "is " << fi(x) << "." << endl;
		}
	}

	return 0;
}

