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
int n, m;
int32_t main()
{
	ACCELERATE;
	cin >> n >> m;
	int lcm = 1, ans = 0, acc = 1, abb = 1;
	rep(i, 1, n) {
		// if (!st[i]) lcm = lcm * i;
		if (__gcd(i, lcm) == 1) lcm = lcm * i;
		int cnt = m / lcm;
		abb = (abb * (cnt % P)) % P;
		acc = (acc * (m % P)) % P;
		ans = (ans + (acc - abb + P) % P) % P;
		// cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}