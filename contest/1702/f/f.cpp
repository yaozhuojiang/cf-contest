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
int n, a[N], b[N];
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		multiset<int> mse;
		rep(i, 1, n) {
			cin >> a[i];
			while (a[i] % 2 == 0) a[i] /= 2;
			mse.insert(a[i]);
		}
		rep(i, 1, n) {
			cin >> b[i];
			while (b[i] % 2 == 0) b[i] /= 2;
			while (b[i]) {
				auto pos = mse.lower_bound(b[i]);
				if (pos != mse.end() && *pos == b[i]) {
					mse.erase(pos);
					break;
				} else {
					b[i] /= 2;
				}
			}
		}
		cout << (mse.empty() ? "YES" : "NO") << endl;
	}
	return 0;
}