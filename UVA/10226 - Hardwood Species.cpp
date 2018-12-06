#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int main() {
	int n;
	int c = 0;
	string x, blank;
	map<string, double> m;
	map<string, double>::iterator it;
//	freopen("in.txt", "r", stdin);
	//////////
	cin >> n;
	getchar();
	getline(cin, x);
	int i = 0;
	while (i < n) {
		while (getline(cin, x) && x != "") {
			if (m.find(x) == m.end()) {
				m[x] = 1;
			} else {
				m[x]++;
			}
			c++;
		}
		if (i != 0) {
			cout <<endl;
		}
		for (it = m.begin(); it != m.end(); ++it) {
			cout << it->first << " " << fixed << setprecision(4)
					<< (it->second / c * 100) << endl;
		}
		m.clear();
		c = 0;
		i++;
	}
	return 0;
}

