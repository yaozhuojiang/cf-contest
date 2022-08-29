#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define db double
#define ll long long
#define pb push_back
#define lchild (k<<1)
#define rchild (k<<1|1)
#define pii pair<int,int>
#define mm(a,b) memset(a,b,sizeof(a))
#define rush() int T; cin >> T; while (T--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ACCELERATE (ios::sync_with_stdio(false),cin.tie(0))
const int N = 2e2 + 5;
const int M = 5e2 + 5;
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
pair<int, int> e[M];
int ask(string &s)
{
	cout << "? " << s << endl;
	cout.flush();
	int v;
	cin >> v;
	return v;
}
int main()
{
	ACCELERATE;
	cin >> n >> m;
	string s = "";
	rep(i, 1, m) s += '0';
	rep(i, 1, m) {
		s[i - 1] = '1';
		e[i].fi = ask(s);
		e[i].se = i;
		s[i - 1] = '0';
	}
	s[m - 1] = '0';
	sort(e + 1, e + m + 1);
	int pre = 0, now;
	rep(i, 1, m) {
		s[e[i].se - 1] = '1';
		now = ask(s);
		if (e[i].fi + pre != now) s[e[i].se - 1] = '0';
		else pre = now;
	}
	cout << "! " << pre << endl;
	return 0;
}