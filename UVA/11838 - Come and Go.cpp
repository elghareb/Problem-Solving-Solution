#include <bits/stdc++.h>
#define SZ(x) (int)x.size()
using namespace std;
#define MAX 2000

vector<int> adj[MAX + 1];
int dfs_low[MAX + 1];
int dfs_num[MAX + 1];
int vis[MAX + 1];
vector<int> s;
int dfsNumCount;
int numSCC;
int n, m;

void SCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumCount++;
	s.push_back(u);
	vis[u] = 1;
	for (int i = 0; i < SZ(adj[u]); ++i) {
		int v = adj[u][i];
		if (dfs_num[v] == -1) {
			SCC(v);
		}
		if (vis[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	if (dfs_low[u] == dfs_num[u]) {
		numSCC++;
		int v;
		while (1) {
			v = s.back();
			s.pop_back();
			vis[v] = 0;
			if (u == v) {
				break;
			}
		}
	}
}
void reset() {
	s.clear();
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		dfs_low[i] = 0;
		dfs_num[i] = -1;
		vis[i] = 0;
	}
	numSCC = 0;
	dfsNumCount = 1;

}
int main() {

//	freopen("in.txt", "rt", stdin);

	int a, b, c;
	while (cin >> n >> m && (n && m)) {
		reset();
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> c;
			adj[a].push_back(b);
			if (c == 2) {
				adj[b].push_back(a);
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (dfs_num[i] == -1) {
				SCC(i);
			}
		}
		cout << (numSCC == 1) << endl;
	}
	return 0;
}

