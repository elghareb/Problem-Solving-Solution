#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

void solve(int n, string x) {
	string temp;
	string z = "";
	n = SZ(x) / n;
	for (int i = 0; i < SZ(x); i += n) {
		temp = "";
		for (int j = i; j < i + n; ++j) {
			temp += x[j];
		}
		reverse(ALL(temp));
		z += temp;
	}
	cout << z << endl;
}

int main() {
	string x;
	int n;
	while (cin >> n && n != 0) {
		cin >> x;
		solve(n, x);
	}

	return 0;
}

