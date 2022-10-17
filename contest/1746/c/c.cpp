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
int n, a[N], mx[N], ans[N];
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		ans[a[n]] = 1;
		rep(i, 2, n) {
			ans[a[i - 1]] = i;
		}
		rep(i, 1, n) cout << ans[i] << " ";
		cout << endl;
		// rep(i, 1, n) mx[i] = max(mx[i - 1], a[i]);
		// vector<pii> ve;
		// rep(i, 1, n) {
		// 	ve.push_back({mx[i] - a[i], i});
		// }
		// sort(ve.begin(), ve.end());
		// for (int i = n; i >= 0; i--) ans[i] = ve[i - 1].second;
		// // for (int i = 0; i < n; i++) ans[i + 1] = ve[i].second;
		// for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		// cout << endl;
	}
	return 0;
}