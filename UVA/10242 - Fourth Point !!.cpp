#include <bits/stdc++.h>
#include <unordered_map>
#include <time.h>
//#include <iostream>

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

	double x, y;
	pair<double, double> d[3];
	map<pair<double, double>, int> m;

	while (cin >> x >> y) {
		m.clear();
		m[make_pair(x, y)]++;

		for (int i = 0; i < 3; ++i) {
			cin >> x >> y;
			m[make_pair(x, y)]++;
		}
		for (auto it : m) {
			int z = it.second;
			if (z == 2) {
				d[1] = it.first;
			}
			if (z == 1) {
				d[0] = it.first;
			}
		}
		for (auto it : m) {
			int z = it.second;
			if (z == 1) {
				d[2] = it.first;
				break;
			}
		}

		//d[0] && d[2] ==>end point of two segment
		//d[1] ==> mutual point

		x = d[0].first - d[1].first + d[2].first;
		y = d[0].second - d[1].second + d[2].second;
		cout << fixed<<setprecision(3) << x << " " << y << endl;

	}

#ifndef ONLINE_JUDGE
	clock_t stop = clock();
	double elapsed_secs = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Time elapsed in s :" << elapsed_secs << endl;
#endif
	return 0;
}

