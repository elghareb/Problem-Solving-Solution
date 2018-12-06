#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

int main() {

	string a;
	int c = 0;
	while (getline(cin, a)) {
		for (int i = 0; i < SZ(a); ++i) {
			if (a[i] == '"') {
				if (c % 2 == 0) {
					cout << "``";
					c++;
				} else {
					cout << "''";
					c = 0;
				}
			} else {
				cout << a[i];
			}
		}
		cout << endl;
	}

	return 0;
}

