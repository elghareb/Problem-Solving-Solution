#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()

using namespace std;

int main() {

	string name;
	map<string, int> m;
	vector<string> a;
	int n, value, num;
	int x = 0;
	while (cin >> n) {
		if (x != 0) {
			cout << endl;
		}
		/////////////////////////////////////
		for (int i = 0; i < n; ++i) {
			cin >> name;
			m[name] = 0;
			a.push_back(name);
		}
		///////////////////////////////////
		for (int i = 0; i < n; ++i) {
			cin >> name >> value >> num;
			if (num == 0)
				continue;
			m[name] -= value;
			m[name] += value % num;
			for (int j = 0; j < num; ++j) {
				cin >> name;
				m[name] += value / num;
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " " << m[a[i]] << endl;
		}
		m.clear();
		a.clear();
		x++;
	}

	return 0;
}

