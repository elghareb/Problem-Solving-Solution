#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int main() {
//	freopen("in.txt", "rt", stdin);
//
	int n;
	long long prod, mx;
	int c = 0;
	long long arr[20];
	while (scanf("%d", &n) == 1) {
		mx = 0;
		c++;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			mx = max(arr[i], mx);
		}
		///////////////////////////////////////////////
		for (int i = 0; i < n; ++i) {
			prod = 1;
			for (int j = i; j < n; ++j) {
				prod *= arr[j];
				mx = max(prod, mx);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", c, mx);
	}
	return 0;
}

