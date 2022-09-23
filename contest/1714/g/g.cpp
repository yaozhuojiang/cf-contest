#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define db double
#define int long long
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
int n, p, a, b, r[N];
// remember to init
struct edge {
	int u, v, a, b, next;
} edges[M];
int head[N], tot;
void init()
{
	mm(head, -1);
	tot = 0;
}
void add_edges(int u, int v, int a, int b)
{
	edges[tot].u = u; edges[tot].v = v; edges[tot].a = a; edges[tot].b = b; edges[tot].next = head[u]; head[u] = tot++;
	edges[tot].u = v; edges[tot].v = u; edges[tot].a = a; edges[tot].b = b; edges[tot].next = head[v]; head[v] = tot++;
}
set<pii> see;
int d1[N], d2[N], d3[N];
void dfs(int u, int f)
{
	if (u != 1) {
		// cout << u << " " << d1[u] << endl;
		// for (auto &x : see) cout << x.fi << " " << x.se << endl;
		// cout << endl;
		auto pos = see.lower_bound({d1[u], 0});
		if ((*pos).fi == d1[u]) r[u] = (*pos).se;
		else if (pos == see.begin()) r[u] = 0;
		else {
			pos--;
			r[u] = (*pos).se;
		}
	}
	for (int i = head[u]; ~i; i = edges[i].next) {
		int v = edges[i].v, a = edges[i].a, b = edges[i].b;
		if (v == f) continue;
		d1[v] = d1[u] + a;
		d2[v] = d2[u] + b;
		d3[v] = d3[u] + 1;
		see.insert({d2[v], d3[v]});
		dfs(v, u);
		see.erase({d2[v], d3[v]});
	}

}
int32_t main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		rep(i, 1, n) head[i] = -1, d1[i] = d2[i] = d3[i] = 0, r[i] = 0;
		tot = 0;
		rep(i, 2, n) {
			cin >> p >> a >> b;
			add_edges(p, i, a, b);
		}
		// for (int i = head[4]; ~i; i = edges[i].next) cout << edges[i].v << " ";
		// cout << endl;
		see.clear();
		dfs(1, -1);
		rep(i, 2, n) cout << r[i] << " ";
		cout << endl;
	}
	return 0;
}