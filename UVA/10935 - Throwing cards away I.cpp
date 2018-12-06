#include <bits/stdc++.h>
#include <bitset>
#define SZ(x)       (int)(x).size()
#define ALL(X)      (X).begin(),(X).end()
#define ALLR(X)     (X).rbegin(),(X).rend()
#define clr(v,d)    memset(v,d,sizeof(v))
using namespace std;
typedef long long ll;

int main() {

	queue<int> p;
	vector<int> v;
	int n;
	int j;

	while (cin >> n && n != 0) {
		if (n == 1) {
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: 1" << endl;
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			if (i % 2 != 0) {
				v.push_back(i);

			} else {
				p.push(i);
			}
		}
		if (n % 2 == 0) {
			j = 1;
		} else {
			j = 0;
		}
		while (p.size() != 1) {
			n = p.front();
			p.pop();
			if (j % 2 == 0) {
				p.push(n);
			} else {
				v.push_back(n);
			}
			j++;
		}
		cout << "Discarded cards: ";
		for (int i = 0; i < SZ(v) - 1; ++i) {
			cout << v[i] << ", ";
		}
		cout << v[SZ(v) - 1] << endl;
		cout << "Remaining card: " << p.front() << endl;
		p.pop();
		v.clear();
	}

	return 0;
}

