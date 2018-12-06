#include <bits/stdc++.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
//	ios_base::sync_with_stdio(0);

	vector<int> v;
	int c, s, x;
	double avg, imb;
	int z = 0;
	while (cin >> c >> s) {
		v.clear();
		avg = 0;
		imb = 0;
		for (int i = 0; i < s; ++i) {
			cin >> x;
			avg += x;
			v.push_back(x);
		}
		avg = 1.0 * accumulate(ALL(v),0) / c;

		for (int i = s; i < 2 * c; ++i) {
			v.push_back(0);
		}

		sort(ALL(v), greater<int>());

		cout << "Set #" << ++z << endl;
		for (int i = 0; i < c; ++i) {
			cout << " " << i << ":";
			if (v[i]) {
				cout << " " << v[i];
			}
			if (v[2 * c - i - 1]) {
				cout << " " << v[2 * c - i - 1];
			}
			imb += fabs(v[i] + v[2 * c - i - 1] - avg);
			cout << endl;
		}
		printf("IMBALANCE = %.5lf\n\n", imb);
	}
	return 0;
}


