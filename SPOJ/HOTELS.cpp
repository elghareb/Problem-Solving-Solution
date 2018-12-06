#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define FOR(i,n) for(int i=1;i<=n;i++)
#define INF 1<<30

//int can(int v, int m, int d, int p) {
//	double percentag = (p * 1.0 / 100.0) + 1;
//	double value = v * 1.1;
//
//	for (int i = 0; i < m; ++i) {
//		value = (value * percentag) - d;
//	}
//	return value;
//}

int main() {

	int arr[300010];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int mx = 0;
	int sum = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while (sum+arr[j] <=m && j < n) {
			sum += arr[j];
			j++;
		}
		mx = max(sum, mx);
		sum = sum- arr[i];
	}
	cout << mx << endl;

	return 0;
}
