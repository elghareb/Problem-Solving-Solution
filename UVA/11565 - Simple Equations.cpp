#include <bits/stdc++.h>

using namespace std;

int main() {

	bool sol = false;
	int n, a, b, c;
	cin >> n;
	while (n--) {
		sol = false;

		cin >> a >> b >> c;
		for (int i = -100; i <= 100 && !sol; ++i) {
			for (int j = -100; j < 100 && !sol; ++j) {
				for (int k = -100; k < 100 && !sol; ++k) {
					if ((i !=j && k != j && i != k) && i + j + k == a && i * j * k == b
							&& i * i + j * j + k * k == c) {
						cout << i << " " << j << " " << k << endl;
						sol = true;
					}
				}
			}
		}
		if (!sol) {
			cout << "No solution." << endl;
		}
	}
	return 0;
}

