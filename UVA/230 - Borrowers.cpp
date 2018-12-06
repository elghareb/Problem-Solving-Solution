#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
int p = 0;
string a;
vector<pair<string, string> > s;
vector<pair<string, string> > r;

int find(string x) {
	for (int i = 0; i < SZ(s); ++i) {
		if (x == s[i].second) {
			return i;
		}
	}
	return -1;
}
int main() {

	while (getline(cin, a) && a != "END") {
		p = a.find("by");
		s.push_back(make_pair(a.substr(p + 3), a.substr(0, p - 1)));
	}
	sort(ALL(s));
//	for (int i = 0; i < SZ(s); ++i) {
//		cout << s[i].second << " " << s[i].first<< endl;
//	}

	string x, y, z;
	//////////////////////////////////////////////////////////
	while (getline(cin, z)) {
		x = z.substr(0, 6);
		if (x == "BORROW") {
			continue;
		}
		if (SZ(z) > 6) {
			y = z.substr(7);
			int l = y.rfind("\"");
			y = y.substr(0, l + 1);
		}
		if (x == "RETURN") {
			p = find(y);
			string n;
			if (p == 0) {
				n = "Put " + s[p].second + " first";
				r.push_back(make_pair(s[p].first, n));
			} else {
				n = "Put " + s[p].second + " after " + s[p - 1].second;
				r.push_back(make_pair(s[p].first, n));
			}
		} else if (x == "SHELVE") {
			if (SZ(r) == 0) {
				cout << "END" << endl;
				continue;
			}
			sort(ALL(r));
			for (int i = 0; i < SZ(r); ++i) {
				cout << r[i].second << endl;
			}
			cout << "END" << endl;
			r.clear();
		} else if (x == "END") {
			break;
		}
	}

	return 0;
}

