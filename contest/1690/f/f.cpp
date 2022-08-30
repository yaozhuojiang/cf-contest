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
const int N = 2e5 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
string s;
int n, p[N];
vector<bool> vis;
vector<vector<int> > e;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
string dfs(int u)
{
	vis[u] = true;
	string t = "";
	t += s[u];
	for (auto &v : e[u]) {
		if (!vis[v]) t += dfs(v);
	}
	return t;
}
int solve(string &s)
{
	int n = s.size();
	rep(i, 1, n) {
		if (n % i == 0) {
			string t = s.substr(i) + s.substr(0, i);
			if (s == t) return i;
		}
	}
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> s;
		s = '#' + s;
		e = vector<vector<int> > (n + 1);
		rep(i, 1, n) {
			cin >> p[i];
			e[p[i]].push_back(i);
		}
		vis = vector<bool>(n + 1, false);
		vector<int> num;
		rep(i, 1, n) {
			if (!vis[i]) {
				string t = dfs(i);
				num.push_back(solve(t));
			}
		}
		ll ans = 1;
		for (auto &x : num) ans = lcm(ans, x);
		cout << ans << endl;
	}
	return 0;
}