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
		int l = mp[0], r = l;
		ll ans = 1ll;
		rep(i, 1, n - 2) {
			int idx = mp[i];
			if (idx > r) r = idx;
			else if (idx < l) l = idx;
			else {
				// cout << i << " " << " " << l << " " << r << " " << (r - l - 1 - ask(1, 1, n, l + 1, r - 1)) << endl;
				ans = (ans * (r - l + 1 - i)) % P;
			}
		}
		cout << ans << endl;
	}
	return 0;
}