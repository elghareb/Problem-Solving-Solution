#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int arr[110];

bool check(long long x) {
	int t = 0;
	int mask = 0;
	while (x) {
		t = x % 10;
		x /= 10;
		if (mask& (1 << t)) {
			return false;
		}
		mask |= (1 << t);
	}

	return true;
}
unsigned long long s2, j, mx, n;
int main() {
//		freopen("in.txt", "rt", stdin);

	int t;

	scanf("%d", &t);

	while (t--) {
		scanf("%llu", &n);
		mx = 9876543210 / n;
		for (s2 = 1; s2 <= mx; ++s2) {
			if (check(n * s2) && check(s2)) {
				printf("%llu / %llu = %llu\n", n * s2, s2, n);
			}
		}
		if (t) {
			cout << endl;
		}
	}

	return 0;
}

