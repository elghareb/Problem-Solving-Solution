#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (int)(X).size()
#define ALL(X) (X).begin(),(X).end()
#define ALLR(X) (X).rbegin(),(X).rend()
using namespace std;

string RotateHorizontal(string s1) {
	string ret = s1;
	ret[1] = s1[2];
	ret[2] = s1[4];
	ret[3] = s1[1];
	ret[4] = s1[3];
	return ret;
}
string RotateVertical(string s1) {
	string ret = s1;
	ret[0] = s1[4];
	ret[1] = s1[0];
	ret[5] = s1[1];
	ret[4] = s1[5];
	return ret;
}

string solve(string x, string y, int iteration = 0) {
	if (x == y) {
		return "TRUE";
	}
	if (iteration > 4) {
		return "FALSE";
	}
	if (solve(RotateHorizontal(x), y, iteration + 1) == "TRUE") {
		return "TRUE";
	}
	if (solve(RotateVertical(x), y, iteration + 1) == "TRUE") {
		return "TRUE";
	}
	return "FALSE";

}
int main() {
//	freopen("in.txt", "rt", stdin);
	string s;
	while (cin >> s) {
		cout << solve(s.substr(0, 6), s.substr(6))<<endl;
	}

	return 0;
}

