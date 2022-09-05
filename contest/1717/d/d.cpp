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
int n, k;
ll qpow(ll a, ll b)
{
	ll ans = 1ll; a %= P;
	for (ll i = b; i; i >>= 1, a = a * a % P) if (i & 1) ans = ans * a % P;
	return ans % P;
}
ll fac[N], inv[N];
void getfac()
{
	fac[0] = inv[0] = 1;
	rep(i, 1, N - 1) fac[i] = (fac[i - 1] * i) % P, inv[i] = (inv[i - 1] * qpow(i, P - 2)) % P;
}
ll getC(ll n, ll m) { return (fac[n] * inv[n - m] % P) * inv[m] % P; }
int main()
{
	ACCELERATE;
	getfac();
	cin >> n >> k;
	if (k >= n) cout << qpow(2, n) << endl;
	else {
		ll ans = 0;
		// rep(i, 0, k) cout << getC(3, i) << endl;
		rep(i, 0, k) ans = (ans + getC(n, i)) % P;
		cout << ans << endl;
	}
	return 0;
}