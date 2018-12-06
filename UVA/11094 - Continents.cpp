#include <bits/stdc++.h>

#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

int n, m;
char grid[300][300];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs(int x, int y, char c) {

	if (grid[x][y] != c) {
		return 0;
	}

	int z = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		if (yy == 0 || yy == m - 1) {
			if (grid[xx][0] == c) {
				q.push(make_pair(xx, 0));
			}
			if (grid[xx][m - 1] == c) {
				q.push(make_pair(xx, m - 1));
			}
		}
		if (grid[xx][yy] == c) {
			z++;
		}
		grid[xx][yy] = '.';
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == c) {
				q.push(make_pair(nx, ny));
			}
		}
	}
	return z;
}

int main() {
//	freopen("in.txt", "rt", stdin);

	int a, b, mx;
	char c;
	while (cin >> n >> m) {
		mx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> grid[i];
		}
		cin >> a >> b;
		c = grid[a][b];
		bfs(a, b, c);
//
//		for (int i = 0; i < n; ++i) {
//			cout << grid[i] << endl;
//		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == c) {
					mx = max(bfs(i, j, c), mx);
				}
			}
		}

		cout << mx << endl;
	}
	return 0;
}

