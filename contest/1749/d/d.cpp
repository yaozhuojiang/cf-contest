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
const int P = 998244353;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int m;
int n, primes[N], cnt, st[N];
void get_primes()
{
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
int32_t main()
{
	ACCELERATE;
	cin >> n >> m;
	get_primes();
	int lcm = 1, ans = 0, acc = 1, abb = 1;
	rep(i, 1, n) {
		if (!st[i]) lcm = lcm * i;
		int cnt = m / lcm;
		abb = (abb * (cnt % P)) % P;
		acc = (acc * (m % P)) % P;
		ans = (ans + (acc - abb + P) % P) % P;
		// cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}