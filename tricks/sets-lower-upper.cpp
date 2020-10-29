#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define clr(a,v) memset(a,v,sizeof a)
#define fs first
#define sd second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x) * (x))

///////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;

///////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-9;
const double INF = 2e10;
///////////////////////////////////////
const ll OO = LONG_LONG_MAX;
int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);

	auto lw = s.lower_bound(1);
	auto up = s.lower_bound(6);

  //lower_bound(x) equal or greater than x
  //upper_bound(x) greater than x

	lw--;
	up++;
	if (lw == s.end()) {
		cout << "YES" << endl;
	} else {
		cout << *lw << endl;
	}
	if (up == s.end()) {
		cout << "YES" << endl;
	} else {
		cout << *up << endl;
	}


  //YES
  //YES

	return 0;

}
