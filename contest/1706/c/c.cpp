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
int n, k, a[N], p[N];
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> k;
		rep(i, 1, n) {
			cin >> a[i];
			p[i] = -1;
		}
		vector<pair<int, int> > v;
		rep(i, 1, n) rep(j, 1, k) v.push_back({a[i] / j, i});
		sort(v.begin(), v.end());
		multiset<int> se;
		int size = v.size(), ans = P;
		rep(i, 0, size - 1) {
			int val = v[i].fi, idx = v[i].se;
			if (p[idx] != -1) {
				auto pos = se.find(p[idx]);
				se.erase(pos);
			}
			p[idx] = val;
			se.insert(val);
			if (se.size() == n) ans = min(ans, val - *se.begin());
		}
		cout << ans << endl;
	}
	return 0;
}