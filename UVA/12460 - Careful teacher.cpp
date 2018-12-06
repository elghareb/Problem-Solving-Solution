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

bool diff(string s1, string s2) {
	int c = 0;

	if (SZ(s1) != SZ(s2)) {
		return false;
	}
	for (int i = 0; i < SZ(s1); ++i) {
		if (s1[i] != s2[i]) {
			c++;
		}
		if (c >= 2) {
			return false;
		}
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif

	map<string, int> m;
	string s1, s2;
	vector<string> s;

	int z = 0;
	while (cin >> s1 && s1 != "--") {
		s.push_back(s1);
		m[s1] = ++z;
	}
	UnionFind u(SZ(s));

	for (int i = 0; i < SZ(s) - 1; ++i) {
		for (int j = i + 1; j < SZ(s); ++j) {
			if (!u.isSame(i + 1, j + 1) && diff(s[i], s[j])) {
				u.unionSet(i + 1, j + 1);
			}
		}
	}
	while (cin >> s1 >> s2) {
		if (m.find(s[1]) != m.end() && m.find(s[2]) != m.end()
				&& u.isSame(m[s1], m[s2])) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

}

