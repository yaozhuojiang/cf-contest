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
int tr[N << 2], a[N], n;
void build(int k, int l, int r)
{
	if (l == r) {
		tr[k] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	tr[k] = tr[lchild] + tr[rchild];
}
void update(int k, int l, int r, int x, int v)
{
	if (l == r) {tr[k] += v; return ;};
	int mid = (l + r) >> 1;
	if (x <= mid) update(lchild, l, mid, x, v);
	else update(rchild, mid + 1, r, x, v);
	tr[k] = tr[lchild] + tr[rchild];
}
int ask(int k, int l, int r, int x, int y)
{
	if (l == x && r == y) return tr[k];
	int mid = (l + r) >> 1;
	if (y <= mid) return ask(lchild, l, mid, x, y);
	else if (x > mid) return ask(rchild, mid + 1, r, x, y);
	else return ask(lchild, l, mid, x, mid) + ask(rchild, mid + 1, r, mid + 1, y);
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		unordered_map<int, int> mp;
		rep(i, 1, n) {
			cin >> a[i];
			mp[a[i]] = i;
		}
		build(1, 1, n);
		int l = mp[0], r = l;
		update(1, 1, n, mp[0], 1);
		ll ans = 1ll;
		rep(i, 1, n - 2) {
			int idx = mp[i];
			if (idx > r) r = idx;
			else if (idx < l) l = idx;
			else {
				// cout << i << " " << " " << l << " " << r << " " << (r - l - 1 - ask(1, 1, n, l + 1, r - 1)) << endl;
				ans = (ans * (r - l - 1 - ask(1, 1, n, l + 1, r - 1))) % P;
			}
			update(1, 1, n, idx, 1);
		}
		cout << ans << endl;
	}
	return 0;
}