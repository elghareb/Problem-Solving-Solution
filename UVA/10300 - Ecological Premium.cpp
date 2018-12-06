#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

using namespace std;

int main() {

	long long sum = 0;
	long long a, b, c;
	int t, f;
	cin >> t;
	while (t--) {
		cin >> f;
		while (f--) {
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << endl;
		sum = 0;
	}

	return 0;
}

