#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

using namespace std;

int first(string n) {
	int sum = 0;
	for (int i = 0; i < SZ(n); ++i) {
		if (isalpha(n[i])) {
			n[i] = tolower(n[i]);
			sum += n[i] - 96;
		}
	}

	while (sum > 9) {
		sum = (sum % 10) + (sum / 10);
	}
	return sum;
}
int main() {
	double x, y;
	string a, b;
	while (getline(cin, a) && getline(cin, b)) {
		x = first(a);
		y = first(b);
		if (x == 0 && y == 0) {
			cout << endl;
			continue;
		}
		cout << fixed << setprecision(2) << min(x, y) / max(x, y) * 100 << " %"
				<< endl;
	}
	return 0;
}

