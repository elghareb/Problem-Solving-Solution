#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;


ull sum[100100];
ull cnt[100100];


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	for (int i = 1; i <= 100000; ++i) {
		for (int j = i; j <= 100000; j += i) {
			cnt[j]++;
			sum[j] += i;
		}

	}
	int T, a, b, k;
	cin >> T;
	while (T--) {
		cin >> a >> b >> k;
		int st = a + (((k - (a % k)) == k) ? 0 : k - (a % k));
//		cout<<st<<endl;
		ll C = 0;
		ll S = 0;
		for (int i = st; i <= b; i += k) {
//			cout << i << " " << cnt[i] << " " << sum[i] << endl;
			C += cnt[i];
			S += sum[i];
		}
		cout << C << " " << S << endl;
	}

	return 0;
}

