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
int n, k, p[N], s[N], cnt[N];
// remember to init
struct edge {
	int u, v, w, next;
} edges[M];
int head[N], tot;
void init()
{
	rep(i, 1, n) head[i] = -1, cnt[i] = 0;
	tot = 0;
}
void add_edges(int u, int v, int w)
{
	edges[tot].u = u; edges[tot].v = v; edges[tot].w = w; edges[tot].next = head[u]; head[u] = tot++;
	edges[tot].u = v; edges[tot].v = u; edges[tot].w = w; edges[tot].next = head[v]; head[v] = tot++;
}
map<pii, ll> mp;
void dfs(int u, int f, int c)
{
	ll beg = 1ll * c * s[u];
	mp[{u, c}] = beg;
	if (cnt[u] == 0) {
		mp[{u, c + 1}] = mp[{u, c}] + s[u];
		return ;
	}
	int base = c / cnt[u], mod = c % cnt[u];
	vector<ll> arrs;
	for (int i = head[u]; ~i; i = edges[i].next) {
		int v = edges[i].v;
		if (v == f) continue;
		dfs(v, u, base);
		mp[{u, c}] += mp[{v, base}];
		arrs.push_back(mp[{v, base + 1}] - mp[{v, base}]);
	}
	sort(arrs.begin(), arrs.end());
	for (int i = arrs.size() - 1, j = 0; j <= mod; j++, i--) {
		if (j < mod) mp[{u, c}] += arrs[i];
		else {
			mp[{u, c + 1}] = mp[{u, c}];
			mp[{u, c + 1}] += s[u];
			mp[{u, c + 1}] += arrs[i];
		}
	}
	// cout << u << " " << c << " " << mp[{u, c}] << " " << mp[{u, c + 1}] << endl;
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> k;
		init();
		mp.clear();
		rep(i, 2, n) {
			cin >> p[i];
			cnt[p[i]]++;
			add_edges(p[i], i, 0);
		}
		rep(i, 1, n) cin >> s[i];
		dfs(1, -1, k);
		cout << mp[{1, k}] << endl;
	}
	return 0;
}