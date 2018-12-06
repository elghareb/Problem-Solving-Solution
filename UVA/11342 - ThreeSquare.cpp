#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

void fun(int maps[][4]) {

	for (int i = 0; i <= 224; ++i) {
		for (int j = i; j <= 224; ++j) {
			for (int k = j; k <= 224; ++k) {
				int n = i * i + j * j + k * k;
				if (n > 50000) {
					break;
				}
				if (maps[n][0] == 0) {
					maps[n][0] = 1;
					maps[n][1] = i;
					maps[n][2] = j;
					maps[n][3] = k;
				}
			}
		}
	}
}

int main() {
	int m[50001][4];
	memset(m, 0, sizeof(int) * (50001) * 4);
	fun(m);

	int n, k;
	cin >> n;

	while (n--) {
		cin >> k;
		if (m[k][0] == 0) {
			cout << -1 << endl;
		} else {
			cout << m[k][1] << " " << m[k][2] << " " << m[k][3] << endl;
		}
	}
	return 0;
}

