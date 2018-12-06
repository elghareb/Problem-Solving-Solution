#include <bits/stdc++.h>
#define SZ(x) (int)x.size()
using namespace std;

int vis[201];
map<string, int> m;
vector<int> adj[201];
int in_edge[201];
string name[201];
vector<string> res;
int n, e;
void topo_kahn(int s) {
	res.push_back(name[s]);
	vis[s] = 1;
	for (int i = 0; i < SZ(adj[s]); ++i) {
		int child = adj[s][i];
		in_edge[child]--;
	}

}

void init() {
	res.clear();
	m.clear();
	memset(vis, 0, sizeof vis);
	memset(in_edge, 0, sizeof in_edge);
	for (int i = 0; i < 200; ++i) {
		adj[i].clear();
	}
}
int main() {

//	freopen("in.txt", "rt", stdin);
	string a, b;
	int t = 0;
	while (cin >> n) {
		init();
		// node name string and hash it
		for (int i = 0; i < n; ++i) {
			cin >> a;
			m[a] = i;
			name[i] = a;
		}
		// edge connection
		cin >> e;
		for (int i = 0; i < e; ++i) {
			cin >> a >> b;
			adj[m[a]].push_back(m[b]);
		}
		// calculate in_edge
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < SZ(adj[i]); ++j) {
				int child = adj[i][j];
				in_edge[child]++;
			}

		}
		// calculate toposort
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n; ++i) {
				if (!vis[i] && in_edge[i] == 0) {
					topo_kahn(i);
					break;
				}
			}
		}


		printf("Case #%d: Dilbert should drink beverages in this order: ", ++t);
		for (int i = 0; i < SZ(res) - 1; ++i) {
			cout << res[i] << " ";
		}
		cout << res[SZ(res) - 1] << "." << endl<<endl;
	}
	return 0;
}

