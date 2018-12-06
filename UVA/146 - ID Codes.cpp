#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

int main() {

	string a, b;

	while (cin >> a && a != "#") {
		b = a;
		next_permutation(ALL(a));
		sort(ALL(b));
		if (a == b) {
			cout << "No Successor" << endl;
		} else
			cout << a << endl;
	}

	return 0;
}

