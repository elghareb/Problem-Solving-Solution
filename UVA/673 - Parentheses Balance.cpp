#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

void solve(string x) {
	stack<char> s;
	int c = 0;

	for (int i = 0; i < SZ(x); ++i) {
		if(x[i]==' '){
			continue;
		}
		if (x[i] == '(' || x[i] == '[') {
			s.push(x[i]);
		} else if (s.empty()) {
			c++;
			continue;
		} else if (x[i] == ']' && s.top() == '[') {
			s.pop();
		} else if (x[i] == ')' && s.top() == '(') {
			s.pop();
		}
	}
	if (!c && !s.size()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}

int main() {

	string x;
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, x);
		solve(x);
	}
	return 0;
}

