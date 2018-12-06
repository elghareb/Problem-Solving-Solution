#include <bits/stdc++.h>
#include <unordered_map>
#include <functional>

#define SZ(s) ((int)s.size())
#define ALL(s) s.begin(),s.end()

using namespace std;

int arr1[100010];
int arr2[100010];
long long acc1[100010];
long long acc2[100010];

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//	int arr[100];
//	int n;
//	arr[0]=0;
//	cin >> n;
//	for (int i = 1; i <=n; ++i) {
//		cin >> arr[i];
//	}
//	int m,x;
//	cin>>m;
//	for (int i = 0; i < m; ++i) {
//		cin>>x;
//		int j = lower_bound(arr,arr+n+1,x)-(arr);
//		cout<<j<<endl;
//	}

	int n, m;
	while (cin >> n && n != 0) {
		memset(arr1, 0, sizeof arr1);
		memset(arr2, 0, sizeof arr2);
		memset(acc1, 0, sizeof acc1);
		memset(acc2, 0, sizeof acc2);

		for (int i = 1; i <= n; ++i) {
			cin >> arr1[i];
			acc1[i] = arr1[i];
			acc1[i] += acc1[i - 1];
		}
		cin >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> arr2[i];
			acc2[i] = arr2[i];
			acc2[i] += acc2[i - 1];
		}
		int last1 = 0;
		int last2 = 0;

		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			int it = lower_bound(arr2+1, arr2 + m, arr1[i]) - (arr2);

			if (arr1[i] == arr2[it]) {

//				cout << acc1[i] - acc1[last1] << " "
//						<< acc2[it + 1] - acc2[last2] << endl;

				ans += max(acc1[i] - acc1[last1], acc2[it] - acc2[last2]);
				last1 = i;
				last2 = it;
			}
		}
		ans += max(acc1[n] - acc1[last1], acc2[m] - acc2[last2]);
		cout << ans << endl;
	}
	return 0;
}
