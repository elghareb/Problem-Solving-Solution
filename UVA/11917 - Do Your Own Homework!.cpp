#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int main() {
	string sub;
	int b;
	int j, t, k, d;
	j = 0;
	map<string, int> m;
	/////////////////////
//	freopen("in.txt", "r", stdin);
	cin >> t;

	while (j++ < t) {
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> sub >> b;
			m[sub] = b;
		}
		cin >> d;
		cin >> sub;
		cout << "Case " << j << ": ";

		if (m.find(sub) == m.end() || m[sub] > d + 5) {
			cout << "Do your own homework!" << endl;
		} else if (m[sub] <= d) {
			cout << "Yesss" << endl;
		} else if (m[sub] <= d + 5) {
			cout << "Late" << endl;
		}
		m.clear();
	}
	return 0;
}

