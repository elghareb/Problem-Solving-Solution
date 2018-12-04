#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include<fstream>
#include <time.h>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
#include <map>
using namespace std;
typedef long long ll;
const int N = 30002;
const int M = 1000000007;
const int B = 27;
int L[N], R[N], p[N] = { 1 };
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
//	freopen("myfile.in", "r", stdin);
#endif
	int k;
	string s;
	cin >> k >> s;
	s = "a" + s;
	int n = s.size();
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] * (ll) B % M;
	for (int i = 1; i <= n; ++i)
		L[i] = ((ll) L[i - 1] * B + s[i] - 'a' + 1) % M;
	for (int i = n; i > 0; --i)
		R[i] = ((ll) R[i + 1] * B + s[i] - 'a' + 1) % M;
	int res = 0;
	for (int i = 1; i + k <= n + 1; ++i) {
		int l = i, r = i + k - 1;
		int h1 = ((L[r] - (ll) L[l - 1] * p[r - l + 1]) % M + M) % M;
		int h2 = ((R[l] - (ll) R[r + 1] * p[r - l + 1]) % M + M) % M;
		res += h1 == h2;
	}
	cout << res << endl;
	return 0;
}
