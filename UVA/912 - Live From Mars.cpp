#include <bits/stdc++.h>
#include <unordered_map>
#include <time.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;

int main() {

#ifndef ONLINE_JUDGE
	clock_t start = clock();
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);

	int n;
	char x;
	string s1;
	string s2;
	int t = 0;
	while (cin >> n) {
		s1 = "";
		s2 = "";
		if (t != 0) {
			cout << endl;
		}
		t++;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			s1 += x;
		}
		for (int i = 0; i < n; ++i) {
			cin >> x;
			s2 += x;
		}
		bool ans = 1;
		for (int i = 0; i < n; ++i) {
			if (isalpha(s1[i]) && isalpha(s2[i]) && s1[i] - s2[i] != 0) {
				ans = 0;
				break;
			}
		}

		map<char, set<char>> m;

		for (int i = 0; i < n; ++i) {
			if (s1[i] == s2[i]) {
				continue;
			}
			if (isalpha(s1[i]) && isdigit(s2[i])) {
				m[s2[i]].insert(s1[i]);
				if (SZ(m[s2[i]]) > 1) {
					ans = 0;
					break;
				}
			} else if (isalpha(s2[i]) && isdigit(s1[i])) {
				m[s1[i]].insert(s2[i]);
				if (SZ(m[s1[i]]) > 1) {
					ans = 0;
					break;
				}
			}
		}

		for (int ii = 0; ii < n; ++ii) {
			for (int i = 0; i < n; ++i) {
				if (s1[i] == s2[i]) {
					continue;
				}
				if (isdigit(s1[i]) && isdigit(s2[i])) {
					if (SZ(m[s1[i]]) == 0 && SZ(m[s2[i]]) == 1) {
						m[s1[i]].insert(*m[s2[i]].begin());
						if (SZ(m[s1[i]]) > 1) {
							ans = 0;
							break;
						}
					}
					if (SZ(m[s1[i]]) == 1 && SZ(m[s2[i]]) == 0) {
						m[s2[i]].insert(*m[s1[i]].begin());
						if (SZ(m[s2[i]]) > 1) {
							ans = 0;
							break;
						}
					}
					if (SZ(m[s1[i]]) == 1 && SZ(m[s2[i]]) == 1) {
						if (*m[s1[i]].begin() != *m[s2[i]].begin()) {
							ans = 0;
							break;
						}
					}
				}
			}
		}

		for (auto it : m) {
			if (SZ(m[it.first]) > 1) {
				ans = 0;
				break;
			}
		}
		if (!ans) {
			cout << "NO" << endl;

		} else {
			cout << "YES" << endl;
			for (auto it : m) {
				if (SZ(m[it.first])) {
					cout << it.first << " " << *m[it.first].begin() << endl;
				}
			}
		}
	}

#ifndef ONLINE_JUDGE
	clock_t stop = clock();
	double elapsed_secs = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Time elapsed in s :" << elapsed_secs << endl;
#endif
	return 0;
}

