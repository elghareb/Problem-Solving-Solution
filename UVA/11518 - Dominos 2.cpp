#include <bits/stdc++.h>
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
typedef long long ll;

using namespace std;

/*
 * ElFashel
 */

vector<int> adj[10001];
bool vis[10001];
int dfs(int u) {
	if (vis[u]) {
		return 0;
	}
	vis[u] = true;
	int ans = 1;
	for (int i = 0; i < SZ(adj[u]); ++i) {
		int v = adj[u][i];
		if (!vis[v]) {
			ans += dfs(v);
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

	int t;
	int n, m, l;
	int x, y;
	cin >> t;
	while (t--) {
		cin >> n >> m >> l;
		for (int i = 1; i <= 10001; ++i) {
			adj[i].clear();
		}
		memset(vis, 0, sizeof vis);
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 0; i < l; ++i) {
			cin >> x;
			ans += dfs(x);
		}
		cout << ans << endl;
	}
	return 0;
}
