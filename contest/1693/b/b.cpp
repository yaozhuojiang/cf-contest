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
int n, p[N], ans;
ll l[N], r[N], m[N];
vector<vector<int> > e;
void dfs(int u, int f)
{
	ll child = 0;
	for (auto &v : e[u]) {
		dfs(v, u);
		child += m[v];
	}
	if (child < l[u]) {
		ans++;
		m[u] = r[u];
	} else m[u] = min(child, r[u]);
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		e = vector<vector<int> > (n + 1);
		rep(i, 2, n) {
			cin >> p[i];
			e[p[i]].push_back(i);
		}
		rep(i, 1, n) cin >> l[i] >> r[i];
		ans = 0;
		dfs(1, -1);
		cout << ans << endl;
	}
	return 0;
}