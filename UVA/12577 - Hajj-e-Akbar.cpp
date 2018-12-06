#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

int main() {

	int t = 0;
	string a;
	while (cin >> a && a != "*") {
		cout << "Case " << ++t << ": ";
		if (a == "Hajj") {
			cout << "Hajj-e-Akbar" << endl;
		} else {
			cout << "Hajj-e-Asghar" << endl;
		}
	}

	return 0;
}

