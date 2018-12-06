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

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	list<char> ls;

	string s;
	while (cin >> s) {
		auto it = ls.begin();
		for (int i = 0; i < SZ(s); ++i) {
			if (s[i] == '[') {
				it = ls.begin();
			} else if (s[i] == ']') {
				it = ls.end();
			} else {
				ls.insert(it, s[i]);
			}
		}
		for (auto c : ls) {
			cout << c;
		}
		cout << endl;
		ls.clear();
	}

	return 0;

}

