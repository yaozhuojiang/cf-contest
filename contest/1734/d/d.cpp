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
int n, k, a[N], pre[N];
int32_t main()
{
	ACCELERATE;
	rush() {
		cin >> n >> k;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
		int l = k - 1, r = k + 1;
		vector<pii> L, R;
		int cost = 0, bad = INF;
		per(i, k - 1, 1) {
			cost += a[i];
			bad = min(bad, cost);
			if (pre[i - 1] <= pre[l] || i == 1) {
				L.push_back({cost, -bad});
				cost = 0;
				bad = INF;
				l = i - 1;
			}
		}
		rep(i, k + 1, n) {
			cost += a[i];
			bad = min(bad, cost);
			if (pre[i] >= pre[r - 1] || i == n) {
				R.push_back({cost, -bad});
				cost = 0;
				bad = INF;
				r = i + 1;
			}
		}
		int cur = a[k];
		reverse(L.begin(), L.end());
		reverse(R.begin(), R.end());
		while (233) {
			bool flag = false;
			if (!L.empty() && cur >= L.back().second) {
				cur += L.back().first;
				L.pop_back();
				flag = true;
			}
			if (!R.empty() && cur >= R.back().second) {
				cur += R.back().first;
				R.pop_back();
				flag = true;
			}
			if (!flag) break;
			if (L.empty() || R.empty()) break;
		}
		if (L.empty() || R.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}