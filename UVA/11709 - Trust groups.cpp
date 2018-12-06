#include <bits/stdc++.h>
#define SZ(x) (int)x.size()
using namespace std;
#define MAX 1000

int c = 0;
map<string, int> ma;

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
		if (!dfs_num[v]) {
			SCC(v);
		}
		if (vis[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	if (dfs_low[u] == dfs_num[u]) {
		numSCC++;
		while (1) {
			int v = s.back();
			s.pop_back();
			vis[v] = 0;
			if (u == v) {
				break;
			}
		}
	}
}
void reset() {
	ma.clear();
	s.clear();
	numSCC = 0;
	dfsNumCount = 1;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		dfs_low[i] = 0;
		dfs_num[i] = 0;
		vis[i] = 0;
	}

}
int main() {
//	freopen("in.txt", "rt", stdin);

	char names[100];
	string a, b;
	while (scanf("%d %d", &n, &m) && (n)) {
		getchar();
		reset();
		for (int i = 0; i < n; i++) {
			gets(names);
			a = names;
			ma[a] = i + 1;
		}
		for (int i = 0; i < m; i++) {
			gets(names);
			a = names;
			gets(names);
			b = names;
			adj[ma[a]].push_back(ma[b]);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfs_num[i])
				SCC(i);
		}
		printf("%d\n", numSCC);
	}

	return 0;
}

