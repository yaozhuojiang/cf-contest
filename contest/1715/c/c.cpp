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
int n, m, a[N], p, x;
ll dp[N], ans;
int32_t main()
{
	ACCELERATE;
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) dp[i] = dp[i - 1] + (a[i] == a[i - 1] ? 1 : i), ans += dp[i];
	rep(i, 1, m) {
		cin >> p >> x;
		if (a[p] == a[p - 1] && x != a[p - 1]) {
			ans += (n - p + 1) * (p - 1);
		}
		if (a[p] != a[p - 1] && x == a[p - 1]) {
			ans -= (n - p + 1) * (p - 1);
			// cout << p << " " << x << " " << ans << endl;
		}
		if (a[p] != a[p + 1] && x == a[p + 1]) {
			ans -= (n - p) * p;
			// cout << p << " " << x << " " << ans << endl;
		}
		if (a[p] == a[p + 1] && x != a[p + 1]) {
			ans += (n - p) * p;
		}
		a[p] = x;
		cout << ans << endl;
	}
	return 0;
}