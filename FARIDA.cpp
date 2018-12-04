#include bitsstdc++.h
#define SZ(S)  ((int)S.size())
#define ALL(S)  S.begin(),S.end()
using namespace std;

long long arr[10001];
long long dp[10001];
int n;
long long rec(int i) {
	if(i==0){
		return arr[0];
	}
	if (i == 1) {
		return max(arr[0], arr[1]);
	}
	long long &ret = dp[i];
	if (ret != -1) {
		return ret;
	}
	long long c1 = arr[i] + rec(i - 2);
	long long c2 = rec(i - 1);
	return ret = max(c1, c2);
}

int main() {

	int t;
	scanf(%d, &t);
	for (int k = 0; k  t; ++k) {
		scanf(%d, &n);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i  n; ++i) {
			cin  arr[i];
		}
		printf(Case %d %lldn, k + 1, rec(n - 1));
	}

	return 0;
}
