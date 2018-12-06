#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>

#define clr(a,b) memset(a,b,sizeof a)
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

class UnionFind {
public:
	//parent of i = p[i]
	vector<int> p;
	// rank of i
	vector<int> rank;

	UnionFind(int n) {
		p.assign(n + 1, 0);
		rank.assign(n + 1, 0);
		for (int i = 0; i <= n; ++i) {
			p[i] = i;
		}
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSame(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		int x = findSet(i);
		int y = findSet(j);

		if (rank[x] > rank[y]) {

			// x i taller than y
			// connect y to x

			p[y] = x;
		} else {
			// y i taller than x
			// connect x to	y
			p[x] = y;

			// equal
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
	}
};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif

	int n, m, T, x, y;
	int ma[30010];
	T = 0;
	while (cin >> n >> m && n) {
		clr(ma, 0);
		UnionFind u(n);
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			u.unionSet(x, y);
		}
		set<int> s;
		for (int i = 1; i <= n; ++i) {
			s.insert(u.findSet(i));

		}
		cout << "Case " << ++T << ": " << SZ(s) << endl;
	}

}

