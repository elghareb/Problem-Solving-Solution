#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

int main() {

	map<char, double> m;
	int n, t;
	double x;
	char c;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> c >> x;
			m[c] = x;
		}
		cin >> n;
		double cnt = 0;
		string a;
		cin.ignore();
		for (int i = 0; i < n; ++i) {
			a = "";
			getline(cin, a);
			for (int j = 0; j < SZ(a); ++j) {
				if ((int) m.count(a[j]) > 0) {
					cnt += m[a[j]];
				}
			}
		}
		cnt /= 100;
		cout << fixed << setprecision(2) << cnt << "$" << endl;
		cnt = 0;
		m.clear();
	}
	return 0;
}

