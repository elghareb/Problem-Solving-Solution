#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int main() {

	long long n, m, x, c = 0;
	set<long long> a;
	while (cin >> n >> m && (n != 0 || m != 0)) {

		c = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			a.insert(x);
		}
		for (int i = 0; i < m; ++i) {
			cin >> x;
			if (a.find(x) != a.end()) {
				c++;
			}
		}
		a.clear();
		cout << c << endl;
	}
	return 0;
}

