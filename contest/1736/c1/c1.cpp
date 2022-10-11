#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define db double
#define int long long
#define ll long long
#define pb push
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
int n, a[N];
int32_t main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		queue<pii> q;
		rep(i, 1, n) {
			a[i] -= i;
			if (a[i] < 0) q.push({a[i], i});
		}
		q.push({-n, n + 1});
		int ans = 0;
		rep(i, 1, n) {
			while (!q.empty()) {
				auto frt = q.front();
				int v = frt.first + (i - 1), id = frt.second;
				if (v >= 0) {
					q.pop();
				} else {
					break;
				}
			}
			auto frt = q.front();
			int v = frt.first + (i - 1), id = frt.second;
			ans += id - i;
		}
		cout << ans << endl;
	}
	return 0;
}