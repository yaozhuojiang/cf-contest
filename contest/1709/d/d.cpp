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
int n, m, a[N], q, xs, ys, xf, yf, k;
int tr[N << 2];
void build(int k, int l, int r)
{
	if (l == r) {
		tr[k] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	tr[k] = max(tr[lchild], tr[rchild]);
}
void update(int k, int l, int r, int x, int v)
{
	if (l == r) {tr[k] += v; return ;};
	int mid = (l + r) >> 1;
	if (x <= mid) update(lchild, l, mid, x, v);
	else update(rchild, mid + 1, r, x, v);
	tr[k] = max(tr[lchild], tr[rchild]);
}
int ask(int k, int l, int r, int x, int y)
{
	if (l == x && r == y) return tr[k];
	int mid = (l + r) >> 1;
	if (y <= mid) return ask(lchild, l, mid, x, y);
	else if (x > mid) return ask(rchild, mid + 1, r, x, y);
	else return max(ask(lchild, l, mid, x, mid), ask(rchild, mid + 1, r, mid + 1, y));
}
int main()
{
	ACCELERATE;
	cin >> n >> m;
	rep(i, 1, m) cin >> a[i];
	// rep(i, 1, n) {
	// 	rep(j, 1, m) {
	// 		if (i > a[j]) cout << 0 << " ";
	// 		else cout << 1 << " ";
	// 	}
	// 	cout << endl;
	// }
	build(1, 1, m);
	cin >> q;
	rep(i, 1, q) {
		cin >> xs >> ys >> xf >> yf >> k;
		if (ys > yf) swap(xs, xf), swap(ys, yf);
		bool flag = true;
		if ((xf - xs) % k != 0 || (yf - ys) % k != 0) {
			flag = false;
		}
		if (ask(1, 1, m, ys, yf) >= xs + (n - xs) / k * k) flag = false;
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}