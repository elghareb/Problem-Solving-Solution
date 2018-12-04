	#include <bits/stdc++.h>
	#include <unordered_map>
	#include <functional>
	
	#define SZ(s) ((int)s.size())
	#define ALL(s) s.begin(),s.end()
	
	using namespace std;
	
	map<long long, long long> m;
	long long solve(long long n) {
	
		if (n == 0)
			return 0;
		if (m.find(n) != m.end()) {
			return m[n];
		}
	
		long long ans = max(n, solve(n / 3) + solve(n / 2) + solve(n / 4));
		m[n] = ans;
		return ans;
	
	}
	
	int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
	#endif
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
		long long x;
	
	
		while (cin>>x) {
	
			cout << solve(x) << endl;
		}
	//	map<int, int> m;
	//	vector<int> v;
	//
	//	int t;
	//	cin >> t;
	//	while (t--) {
	//		m.clear();
	//		v.clear();
	//		int c = 0;
	//		int xorr = 127;
	//		int n, x;
	//		cin >> n;
	//		for (int i = 0; i < n; ++i) {
	//			cin >> x;
	//			v.push_back(x);
	//		}
	//		for (long long i = 1; i < (1 << n); ++i) {
	//			xorr = 127;
	//			c = 0;
	//			for (long long j = 0; j < n; ++j) {
	//				if (i & (1LL << j)) {
	//					xorr &= v[j];
	//					c++;
	//				}
	//			}
	//			if (xorr == 0) {
	//				m[c]++;
	//			}
	//		}
	//		auto it = m.begin();
	////	cout<<it->first<<endl;
	//		cout << it->second << endl;
	//
	//	}
		return 0;
	}
