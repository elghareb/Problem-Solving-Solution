#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int main() {
	string x;
	int n, k;
	int y = 0;
	map<string, int> m;
	/////////////////
	freopen("in.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (m.find(x) == m.end()) {
			m[x] = y;
		}
	}
	int all = 0;
	while (k--) {
		while (cin >> x && x != ".") {
			if (m.find(x) != m.end()) {
				all += m[x];
			}
		}
		cout << all << endl;
		all = 0;
	}

	return 0;
}

