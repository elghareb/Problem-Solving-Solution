#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

using namespace std;

int sum(int n) {
	int x = 0;
	while (n) {
		x += n % 10;
		n /= 10;
	}
	return x;
}
int main() {

	int n, x;
	while (cin >> n && n != 0) {
		x = sum(n);
		while (1) {
			if (x <= 9) {
				break;
			}
			x = sum(x);
		}
		cout << x << endl;
	}

	return 0;
}

