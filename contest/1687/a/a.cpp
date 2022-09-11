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
const int N = 1e5 + 5;
const int M = 200 + 5;
const int P = 998244353;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dp[2][N];
int n, m, k, u, v;
int main()
{
	ACCELERATE;
	cin >> n >> m >> k;
	map<int, vector<int> > pre;
	vector<int> numbers;
	numbers.push_back(1);
	rep(i, 1, k) {
		cin >> u >> v;
		if (u == v) continue;
		pre[v].push_back(u);
		numbers.push_back(u);
		numbers.push_back(v);
	}
	sort(numbers.begin(), numbers.end());
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
	int r = n - numbers.size();
	n = numbers.size() + 1;
	dp[0][0] = 1;
	ll now = 1, ppp = 0, tmp = 0;
	rep(i, 1, m) {
		ppp = now; now = 0;
		int id = i & 1;
		rep(j, 0, n - 2) {
			tmp = ppp;
			int u = numbers[j];
			tmp = (tmp - dp[id ^ 1][j] + P) % P;
			for (auto &x : pre[u]) {
				int pos = lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin();
				tmp = (tmp - dp[id ^ 1][pos] + P) % P;
			}
			dp[id][j] = tmp;
			now = (now + tmp) % P;
		}
		tmp = ppp;
		tmp = (tmp - dp[id ^ 1][n - 1] + P) % P;
		dp[id][n - 1] = tmp;
		now = (now + tmp * r % P) % P;
	}
	cout << dp[m & 1][0] << endl;
	return 0;
}