#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define clr(a,v) memset(a,v,sizeof a)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x) * (x))

///////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;
///////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-9;
///////////////////////////////////////
const ll OO = (1LL << 60);
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
///////////////////////////////////////

bool vis[101][101][16];
string s[101];
int r, c;

int bfs(pair<int, int> start, pair<string, int> start2) {
	queue<pair<pair<int, int>, pair<string, int>>> q;
	clr(vis, 0);

	q.push( { start, start2 });
	vis[start.first][start.second][0] = 1;

	while (!q.empty()) {
		auto curr = q.front();
		char ch = s[q.front().first.first][q.front().first.second];

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int x = curr.first.first + dx[i];
			int y = curr.first.second + dy[i];

			if (x < 0 || x >= r || y < 0 || y >= c)
				continue;

			ch = s[x][y];

			string z = curr.second.first;
			int dist = curr.second.second;
			int flag = 0;
			if (ch == 'X') {
				return dist + 1;
			}

			//new node
			if ((ch == '#') || (ch == 'B' && z[0] == '0')
					|| (ch == 'Y' && z[1] == '0') || (ch == 'R' && z[2] == '0')
					|| (ch == 'G' && z[3] == '0')) {
				continue;
			}
			if (ch == 'b' || z[0] == '1') {
				z[0] = '1';
				flag += 1;
			}
			if (ch == 'y' || z[1] == '1') {
				z[1] = '1';
				flag += 2;
			}
			if (ch == 'r' || z[2] == '1') {
				z[2] = '1';
				flag += 4;
			}
			if (ch == 'g' || z[3] == '1') {
				z[3] = '1';
				flag += 8;
			}
			if (!vis[x][y][flag]) {
				vis[x][y][flag] = 1;
				q.push( { { x, y }, { z, dist + 1 } });
			}
		}
	}
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> r >> c) {
		if(r==0 || c==0)
			break;
		auto start = mp(-1, -1);
		auto start2 = mp("0000", 0);

		for (int i = 0; i < r; ++i) {
			cin >> s[i];
			for (int j = 0; j < c && start.first == -1; ++j) {
				if (s[i][j] == '*') {
					start= {i,j};
				}
			}
		}
		int ans = bfs(start, start2);
		if (ans == -1) {
			cout << "The poor student is trapped!" << endl;
		} else {
			cout << "Escape possible in " << ans << " steps." << endl;
		}
	}

	return 0;
}

