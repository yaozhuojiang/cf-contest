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
int n, a[N];
ll d[N];
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		ll res = 0;
		rep(i, 1, n) {
			cin >> a[i];
			d[i] = a[i] - a[i - 1];
			if (i >= 2) {
				res += abs(d[i]);
				if (d[i] < 0) d[1] += d[i];
			}
		}
		res += abs(d[1]);
		cout << res << endl;
	}
	return 0;
}