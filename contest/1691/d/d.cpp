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
ll pre[N], suf[N];
int n, a[N], stk[N], tt, Left[N], Right[N];
ll max_pre[N << 2], max_suf[N << 2];
void build(int k, int l, int r)
{
	if (l == r) {
		max_pre[k] = pre[l];
		max_suf[k] = suf[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	max_pre[k] = max(max_pre[lchild], max_pre[rchild]);
	max_suf[k] = max(max_suf[lchild], max_suf[rchild]);
}
ll maxpre(int k, int l, int r, int x, int y)
{
	if (l == x && r == y) return max_pre[k];
	int mid = (l + r) >> 1;
	if (y <= mid) return maxpre(lchild, l, mid, x, y);
	else if (x > mid) return maxpre(rchild, mid + 1, r, x, y);
	else return max(maxpre(lchild, l, mid, x, mid), maxpre(rchild, mid + 1, r, mid + 1, y));
}
ll maxsuf(int k, int l, int r, int x, int y)
{
	if (l == x && r == y) return max_suf[k];
	int mid = (l + r) >> 1;
	if (y <= mid) return maxsuf(lchild, l, mid, x, y);
	else if (x > mid) return maxsuf(rchild, mid + 1, r, x, y);
	else return max(maxsuf(lchild, l, mid, x, mid), maxsuf(rchild, mid + 1, r, mid + 1, y));
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		rep(i, 1, n) {
			cin >> a[i];
			pre[i] = pre[i - 1] + a[i];
		}
		suf[n + 1] = 0;
		per(i, n, 1) suf[i] = suf[i + 1] + a[i];
		build(1, 1, n);
		tt = 0;
		stk[++tt] = 0;
		a[0] = a[n + 1] = P;
		rep(i, 1, n) {
			while (tt && a[stk[tt]] <= a[i]) tt--;
			Left[i] = stk[tt];
			stk[++tt] = i;
		}
		tt = 0;
		stk[++tt] = n + 1;
		per(i, n, 1) {
			while (tt && a[stk[tt]] <= a[i]) tt--;
			Right[i] = stk[tt];
			stk[++tt] = i;
		}
		bool flag = true;
		rep(i, 1, n) {
			if (Left[i] + 1 != i && maxsuf(1, 1, n, Left[i] + 1, i - 1) - suf[i] > 0) flag = false;
			if (Right[i] - 1 != i && maxpre(1, 1, n, i + 1, Right[i] - 1) - pre[i] > 0) flag =false;
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}