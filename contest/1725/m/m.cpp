#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define db double
#define ll long long
#define int long long
#define pb push_back
#define lchild (k<<1)
#define rchild (k<<1|1)
#define pii pair<int,int>
#define mm(a,b) memset(a,b,sizeof(a))
#define rush() int T; cin >> T; while (T--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define ACCELERATE (ios::sync_with_stdio(false),cin.tie(0))
const int N = 4e5 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
// remember to init
struct edge {
	int u, v, w, next;
} edges[N];
int head[N], tot;
int n, m, dist[N], st[N];
void init()
{
	mm(head, -1);
	tot = 0;
}
void add_edge(int u, int v, int w)
{
	edges[tot].u = u; edges[tot].v = v; edges[tot].w = w; edges[tot].next = head[u]; head[u] = tot++;
}
void add_edges(int u, int v, int w)
{
	edges[tot].u = u; edges[tot].v = v; edges[tot].w = w; edges[tot].next = head[u]; head[u] = tot++;
	u += n; v += n;
	edges[tot].u = v; edges[tot].v = u; edges[tot].w = w; edges[tot].next = head[v]; head[v] = tot++;
}
void dijkstra()
{
	rep(i, 1, 2 * n) dist[i] = INF;
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > heap;
    heap.emplace(0, 1);
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        auto ver = t.second, dis = t.first;
        if (st[ver]) continue;
        st[ver] = 1;
        for (int i = head[ver]; ~i; i = edges[i].next) {
            int v = edges[i].v, w = edges[i].w;
            if (dist[v] > dis + w) {
                dist[v] = dis + w;
                heap.emplace(dist[v], v);
            }
        }
    }
}
int32_t main()
{
	ACCELERATE;
	cin >> n >> m;
	init();
	rep(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		add_edges(u, v, w);
	}
	rep(i, 1, n) add_edge(i, i + n, 0);
	dijkstra();
	rep(i, 2, n) {
		int tmp = min(dist[i], dist[i + n]);
		cout << (tmp == INF ? -1 : tmp) << " ";
	}
	return 0;
}