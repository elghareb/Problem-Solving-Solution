#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

inline int triple(int x) {
	return x * x * x;
}

int main() {
//	freopen("in.txt", "rt", stdin);

	for (int a = 2; a <= 200; ++a) {
		for (int b = 2; b < 200; ++b) {
			for (int c = b; c < 200; ++c) {
				for (int d = c; d < 200; ++d) {
					if (triple(a) == triple(b) + triple(c) + triple(d)) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}
			}
		}
	}

	return 0;
}

