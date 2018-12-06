#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int check(int x, int y) {

	int mask = (x < 10000);
	while (x) {
		mask |= 1 << (x % 10);
		x /= 10;
	}
	while (y) {
		mask |= 1 << (y % 10);
		y /= 10;
	}
	if (mask == (1 << 10) - 1) {
		return 1;
	}
	return 0;
}
int main() {
//		freopen("in.txt", "rt", stdin);

	int n, c = 0;
	while (scanf("%d", &n) && n != 0) {
		if (c != 0) {
			cout << endl;
		}
		c = 1;
		int mx = 98765 / n;
		for (int abcde = 1234; abcde <=mx; ++abcde) {
			int fghij = n * abcde;
			if (check(abcde, fghij)) {
				printf("%.5d / %.5d = %d\n", fghij, abcde, n);
				c++;
			}
		}
		if (c == 1) {
			printf("There are no solutions for %d.\n", n);
		}
	}
	return 0;
}

