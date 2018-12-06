#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

int arr[101];
int main() {

	int j = 1;
	int n, sum, c1, c2;
	while (cin >> n && n > 0) {

		sum = 0;
		c1 = 0, c2 = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		sum /= n;
		for (int i = 0; i < n; ++i) {
			if (sum > arr[i]) {
				c1 += sum - arr[i];
			}
			if (arr[i] > sum) {
				c2 += arr[i] - sum;
			}
		}
		cout << "Set #" << j << endl;
		cout << "The minimum number of moves is " << min(c1, c2) << "." << endl;
		cout << endl;
		j++;
	}
	return 0;
}

