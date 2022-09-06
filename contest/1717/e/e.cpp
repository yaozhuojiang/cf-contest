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
int n;
int primes[N], cnt, st[N], euler[N];
void get_eulers()
{
    euler[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt ++ ] = i;
            euler[i] = i - 1; 
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) {
                euler[i * primes[j]] = euler[i] * primes[j];
                break;
            }
            euler[i * primes[j]] = euler[i] * (primes[j] - 1);
        }
    }
	euler[1] = 0;
}
ll qpow(ll a, ll b)
{
	ll ans = 1ll; a %= P;
	for (ll i = b; i; i >>= 1, a = a * a % P) if (i & 1) ans = ans * a % P;
	return ans % P;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b % P; }
int main()
{
	ACCELERATE;
	cin >> n;
	get_eulers();
	ll ans = 0;
	for (ll gcd = 1; gcd <= n; gcd++) {
		for (ll i = 1; i * gcd <= n; i++) {
			ll c = n - i * gcd;
			ll lcm = c / __gcd(c, gcd) * gcd % P;
			ans = (ans + lcm * euler[i] % P) % P;
		}
	}
	cout << ans << endl;
	return 0;
}