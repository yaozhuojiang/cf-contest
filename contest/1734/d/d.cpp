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
const int N = 2e5 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, k, a[N], pre[N];
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> k;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
		int l = k - 1;
		vector<pii> L, R;
		rep(i, k - 1, 1) {
			if (pre[i] <= pre[l] || i == 0) {
				int cur = 0, mn = -INF;
				rep(j, l, i) {
					cur += a[j];
					mn = min(mn, cur);
				}
				l = i - 1;
				L.push_back({cur, mn});
			}
		}
		int r = k + 1;
		rep(i, k + 1, n) {
			if (pre[i] >= pre[r] || i == n) {
				int cur = 0, mn = -INF;
				rep(j, r, i) {
					cur += a[j];
					mn = min(mn, cur);
				}
				r = i + 1;
				R.push_back({cur, mn});
			}
		}
		reverse(L.begin(), L.end());
		reverse(R.begin(), R.end());
		while (233) {
			if (L.

	}
	return 0;
}