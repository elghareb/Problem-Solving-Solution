#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>

#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define clr(a,b) memset(a,b,sizeof a)
#define fr first
#define sc second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll tree[4 * 100100];
ll a[100100];
void build(int i, int li, int ri) {
	// leaf
	if (li == ri) {
		tree[i] = a[li];
		return;
	}
	int mid = (li + ri) / 2;

	build(2 * i + 1, li, mid);
	build(2 * i + 2, mid + 1, ri);

	tree[i] = tree[2 * i + 1] * tree[2 * i + 2];
}

void update(int i, int li, int ri, int idx, int value) {
	// no overlap
	if (li == ri) {
		a[idx] = value;
		tree[i] = value;
		return;
	}
	int mid = (li + ri) / 2;
	if (idx <= mid) {
		update(2 * i + 1, li, mid, idx, value);
	} else {
		update(2 * i + 2, mid + 1, ri, idx, value);
	}
	tree[i] = (tree[2 * i + 1] * tree[2 * i + 2]);
}
int query(int i, int li, int ri, int a, int b) {

	// (li ri) (a  b) (li ri)
	// completely outside the given range
	if (b < li || a > ri) {
		return 1;
	}
	// completely inside the given range
	// (a (li ri)  b)

	if (a <= li && ri <= b) {
		return tree[i];
	}
	int mid = (li + ri) / 2;

	int p1 = query(2 * i + 1, li, mid, a, b);
	int p2 = query(2 * i + 2, mid + 1, ri, a, b);
	return (p1 * p2);
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	char x;
	int n, m, y, z;

	while (cin >> n >> m) {
		clr(tree, 0);
		clr(a, 0);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] >= 1) {
				a[i] = 1;
			}
			if (a[i] <= -1) {
				a[i] = -1;
			}
		}
		build(0, 0, n - 1);

		for (int i = 0; i < m; ++i) {
			cin >> x >> y >> z;
			if (x == 'C') {
				if (z >= 1) {
					z = 1;
				}
				if (z <= -1) {
					z = -1;
				}
				update(0, 0, n - 1, y - 1, z);
			} else {
				int ans = query(0, 0, n - 1, y - 1, z - 1);
				if (ans <= -1) {
					cout << '-';
				} else if (ans == 0) {
					cout << '0';
				} else if (ans >= 1) {
					cout << '+';
				} else {
					cout << ans;
				}
			}
		}
		cout << endl;
	}

	return 0;
}

