#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;



int main() {
//	freopen("in.txt", "rt", stdin);
//	freopen("out.txt", "wt", stdout);

	int n;
	string x;
	while (cin >> n && n) {
		cin >> x;
		int r = 0;
		int d = 0;
		int mn = n;
		bool a = false;
		bool b = false;
		for (int i = 0; i < SZ(x); ++i) {
			if (x[i] == 'R') {
				r = i;
				a = true;
			} else if (x[i] == 'D') {
				d = i;
				b = true;
			} else if (x[i] == 'Z') {
				mn = 0;
				break;
			}
			if (a && b) {
				mn = min(mn, abs(r - d));
			}
		}
		cout << mn << endl;
	}
	return 0;
}

