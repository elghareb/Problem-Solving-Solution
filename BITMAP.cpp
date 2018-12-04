#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x) * (x))

///////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;
///////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-9;
///////////////////////////////////////
const int OO = 1 * 1e9;
const int N = (1 << 17);
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
///////////////////////////////////////
int n, m;
string mask[185];
bool vis[185][185];
int ans[185][185];

queue<pair<pair<int, int>, int>> q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			cin >> mask[i];
			for (int j = 0; j < m; ++j) {
				vis[i][j] = false;
				ans[i][j] = 0;

				if (mask[i][j] == '1') {
					q.push( { { i, j }, 0 });
					vis[i][j] = true;
				}
			}
		}
		while (!q.empty()) {
			auto it = q.front().first;
			int dist = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = it.first + dx[i];
				int ny = it.second + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
					vis[nx][ny] = true;
					q.push( { { nx, ny }, dist + 1 });
					ans[nx][ny] = dist + 1;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << ans[i][0];

			for (int j = 1; j < m; ++j) {
				cout << " " << ans[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}

