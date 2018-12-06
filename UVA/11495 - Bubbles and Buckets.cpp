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

int a[100005];
int inv_c = 0;
void Merge(int start, int mid, int end) {
	int R[100005];
	int L[100005];

	int n = mid - start + 1;
	int m = end - mid;

	for (int i = 0; i < n; ++i) {
		L[i] = a[(start) + i];
	}
	for (int i = 0; i < m; ++i) {
		R[i] = a[(mid + 1) + i];
	}
	int i = 0;
	int j = 0;
	int k = start;
	while (i < n && j < m) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			// for inversion
			// form n to i
			// 1 2 3 (i 4 5 ... n)
			// all element that r < l
			// because right and left are sorted
			inv_c += n - i;
			j++;
		}
		k++;
	}
	while (i < n) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < m) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int start, int end) {
	if (end <= start) {
		return;
	}

	int mid = start + (end - start) / 2;

	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	Merge(start, mid, end);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//  freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n && n) {
		;
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		mergeSort(0, n - 1);

		if (inv_c % 2)
			cout << "Marcelo\n";
		else
			cout << "Carlos\n";
		inv_c = 0;
	}

	return 0;
}

