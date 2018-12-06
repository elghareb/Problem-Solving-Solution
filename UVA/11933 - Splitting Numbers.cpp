#include <bits/stdc++.h>
#include <unordered_map>
#include <functional>

#define SZ(s) ((int)s.size())
#define ALL(s) s.begin(),s.end()

using namespace std;

void solve(int t) {
	int c = 0;
	int c1 = 0;
	int c2 = 0;
	for (int i = 0; i <= 31; ++i) {
		if ((t & (1 << i))) {
		
			if (c % 2 == 0) {
				c1 += (t & (1 << i));
			} else {
				c2 += (t & (1 << i));
			}
			
			c++;
		}
	}
	cout << c1 << " " << c2 << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	while (cin >> t && t != 0) {
		solve(t);
	}

	return 0;
}

