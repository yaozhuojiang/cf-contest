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
int a, b, c, d;
map<int, int> fenjie(int x)
{
	// vector<pii> res;
	map<int, int> res;
	for(int i = 2;i<=x/i;i++){
            if(x%i==0){
                int c = 0;
                while(x%i==0){
                    c++;
                    x/= i;
                }
				res[i] = c;
				// res.push_back({i, c});
                // cout<<i<<' '<<c<<endl;
            }
        }
        // if(x>1)cout<<x<<' '<<1<<endl;
		// if(x > 1) res.push_back({x, 1});
		if (x > 1) res[x] = 1;
		return res;
}
ll qpow(ll a, ll b)
{
	ll ans = 1ll; a %= P;
	for (ll i = b; i; i >>= 1, a = a * a % P) if (i & 1) ans = ans * a % P;
	return ans % P;
}
int32_t main()
{
	ACCELERATE;
	rush() {
		cin >> a >> b >> c >> d;
		int ab = a * b;
		auto ab_val = fenjie(ab);
		bool flag = false;
		rep(i, a + 1, c) {
			auto x_val = fenjie(i);
			int y = 1ll;
			for (auto &x : ab_val) {
				y *= x.second > x_val[x.first] ? qpow(x.first, x.second - x_val[x.first]) : 1ll;
			}
			if (y > d) continue;
			int tmp = (d / y);
			y *= tmp;
			if (y > b && y <= d) {
				flag = true;
				cout << i << " " << y << endl;
				break;
			}
		} 
		if (!flag) cout << -1 << " " << -1 << endl;
	}
	return 0;
}