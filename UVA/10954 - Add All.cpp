#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > q;

void cal() {

	long long cost = 0;
	int x1 = 0, x2 = 0;
	while (q.size() != 1) {
		x1 = q.top();
		q.pop();
		x2 = q.top();
		q.pop();
		q.push(x1 + x2);
		cost += x1 + x2;
		x1 = 0;
		x2 = 0;
	}
	cout << (cost) << endl;
	q.pop();
}

int main() {
	int n;
	int x;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; ++i) {
			cin >> x;
			q.push(x);
		}
		cal();

	}
	return 0;
}

