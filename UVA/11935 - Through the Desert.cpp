#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>
#define clr(a,b) memset(a,b,sizeof a)
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	int d, ld, n, clk;

	while (cin >> d >> s >> s >> n) {
		if (d == 0 && n == 0) {
			break;
		}
		clk = 0;
		ld = 0;
		double fuel = n * 1.0 / 100;
		double ned = 0;
		double ans = 0;
		while (cin >> d >> s) {
			if (s == "Fuel") {
				cin >> s >> n;
			} else if (s == "Gas") {
				cin >> s;
			}
			ned += (fuel + clk) * (d - ld);
			if (s == "station") {
				ans = max(ans, ned);
				ned = 0;
			}
			if (s == "consumption") {
				fuel = n * 1.0 / 100;
			} else if (s == "Leak") {
				clk++;
			} else if (s == "Mechanic") {
				clk = 0;
			} else if (s == "Goal") {
				break;
			}
			ld = d;
		}
		ans = max(ans, ned);
		cout << fixed << setprecision(3) << ans << endl;
	}

	return 0;

}

