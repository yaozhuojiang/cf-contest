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
		int n;
		cin >> n;
		map<int, int> Hash;
		vector<int> pre(n + 1), x(n + 1), dp(n + 1, 0);
		rep(i, 1, n) {
			cin >> x[i];
			if (Hash.find(x[i]) != Hash.end()) pre[i] = Hash[x[i]];
			else pre[i] = i;
			Hash[x[i]] = i;
		}
		int ans = 0, idx;
		rep(i, 1, n) {
			if (pre[i] == i) dp[i] = 1;
			else dp[i] = max(1, dp[pre[i]] - (i - pre[i] - 1) + 1);
			// cout << i << " " << pre[i] << " " << dp[i] << endl;
			if (dp[i] > ans) {
				idx = i;
				ans = max(ans, dp[i]);
			}
		}
		int right = idx;
		while (dp[idx] - dp[pre[idx]] == 1 - (idx - pre[idx] - 1)) idx = pre[idx];
		cout << x[idx] << " " << idx << " " << right << endl;
	}
	return 0;
}