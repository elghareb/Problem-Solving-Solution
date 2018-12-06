#include <bits/stdc++.h>
#include <unordered_map>
#include <time.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

int main() {

#ifndef ONLINE_JUDGE
	clock_t start = clock();
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	int x, y;

	while (cin >> x >> y) {
		int GCD = __gcd(x, y);
		string ans = "";
		if (GCD == 1) {
			ans = "Good Choice";
		} else {
			ans = "Bad Choice";
		}

		cout << right << setw(10) << x;
		cout << right << setw(10) << y;
		cout << "    " << ans << endl;
		cout << endl;
	}

#ifndef ONLINE_JUDGE
	clock_t stop = clock();
	double elapsed_secs = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Time elapsed in s :" << elapsed_secs << endl;
#endif
	return 0;
}

