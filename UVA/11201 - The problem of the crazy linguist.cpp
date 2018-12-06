#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <unordered_map>
#define clr(a,b) memset(a,b,sizeof a)
#define SZ(s) (int)s.size()
#define ALL(s) s.begin(),s.end()

using namespace std;

typedef long long ll;

string odd = "bcdfghjklmnpqrstvwxyz";
string even = "aeiou";
int oc[28];

double p[28] = { 12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44,
		0.00, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90,
		0.02, 0.22, 0.90, 0.52 };

int cnt[8][26];
double pre[8][26];

void gen(int idx, double SBC, int st) {
	cnt[idx - 1][st]++;
	pre[idx - 1][st] += SBC;
	if (idx > 7) {
		return;
	}
	if (idx % 2 != 0) {
		for (int i = 0; i < SZ(odd); i++) {
			if (oc[odd[i] - 'a'] < 2) {
				oc[odd[i] - 'a']++;
				if (idx == 1)
					st = odd[i] - 'a';
				gen(idx + 1, SBC + idx * p[odd[i] - 'a'], st);
				oc[odd[i] - 'a']--;
			}
		}
	} else {
		for (int i = 0; i < SZ(even); i++) {
			if (oc[even[i] - 'a'] < 2) {
				oc[even[i] - 'a']++;
				gen(idx + 1, SBC + idx * p[even[i] - 'a'], st);
				oc[even[i] - 'a']--;
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int t;
	string s;
	cin >> t;

	clr(pre, 0);
	clr(pre, 0);
	gen(1, 0, 0);
	while (t--) {
		cin >> s;
		double x = 0;
		for (int i = 0; i < SZ(s); i++) {
			x += (i + 1) * p[s[i] - 'a'];
		}
		double av = pre[s.size()][s[0] - 'a'] / cnt[s.size()][s[0] - 'a'];
		if (x < av)
			cout << "below\n";
		else
			cout << "above or equal\n";
	}

	return 0;
}

