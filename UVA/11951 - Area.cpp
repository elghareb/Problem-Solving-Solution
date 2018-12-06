#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>

#define clr(a,b) memset(a,b,sizeof a)
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;
const int N = 120;
ll arr[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll n, t, m, K;
	int line = 0;
	cin >> t;
	while (t--) {
		clr(arr, 0);
		cin >> n >> m >> K;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> arr[i][j];
				arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];

			}
		}

		ll sum = 0;
		ll c = 0;
		ll area = 0;
		ll mxarea = 0;
		//(i,j)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				for (int k = i; k <= n; ++k)
					for (int l = j; l <= m; ++l) {

						sum = arr[k][l];
						sum -= arr[i - 1][l];
						sum -= arr[k][j - 1];
						sum += arr[i - 1][j - 1];
						area = (k - i + 1) * (l - j + 1);

						if (sum <= K) {
							if (area == mxarea && c > sum) {
								c = sum;
							} else if (area > mxarea) {
								c = sum;
								mxarea = area;
							}

						}

					}

		cout << "Case #" << ++line << ": ";
		cout << mxarea << " " << c << endl;

	}
	return 0;

}

