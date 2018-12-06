#include <bits/stdc++.h>
#include <unordered_map>
#include <functional>

#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()
using namespace std;
typedef long long ll;

ll LCM(ll a, ll b) {
	return max(a, b) / __gcd(a, b) * min(a, b);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll arr[16];
	vector<ll> tk;

	ll N, M;
	while (cin >> N >> M) {
		ll ans = 0;
		for (int i = 0; i < M; ++i) {
			cin >> arr[i];
		}

		for (int i = 1; i < (1 << M); ++i) {
			for (int j = 0; j < M; ++j) {
				if ((1 << j) & i) {
					tk.push_back(arr[j]);
				}
			}
			ll lcm = tk[0];
			for (int i = 1; i < SZ(tk); ++i) {
				lcm = LCM(lcm, tk[i]);
			}

			if (SZ(tk) % 2 == 0) {
				ans -= (N / lcm);
			} else {
				ans += (N / lcm);
			}
			tk.clear();
		}
		cout << N - ans << endl;
	}

	return 0;

}
