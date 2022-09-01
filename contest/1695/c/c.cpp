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

int main()
{
	ACCELERATE;
	rush() {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > mp(n + 1, vector<int> (m + 1, 0)), mn(n + 1, vector<int> (m + 1, P)), mx(n + 1, vector<int> (m + 1, -P));
		mn[0][1] = mn[1][0] = mx[0][1] = mx[1][0] = 0;
		rep(i, 1, n) rep(j, 1, m) {
			cin >> mp[i][j];
			mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + mp[i][j];
			mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + mp[i][j];
		}
		// cout << mn[n][m] << " " << mx[n][m] << endl;
		if (mn[n][m] <= 0 && mx[n][m] >= 0 && (mn[n][m] % 2 == 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}