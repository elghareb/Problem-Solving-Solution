#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

using namespace std;

void a(int n, int sum) {
}

int main() {

	int n, m;
	while (cin >> n >> m && n >= 0 && m >= 0) {
		cout << min(abs(n - m), 100 - abs(n - m)) << endl;
	}

	return 0;
}

