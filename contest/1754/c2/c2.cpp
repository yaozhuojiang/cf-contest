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
void solve(int sum, vector<bool> &flag)
{
	int j = 0, cnt = 0, bck = abs(sum);
	for (int i = 1; j < bck; i++) {
		if (i - 1 >= 1 && flag[i - 1] != 1 && ((sum > 0 && a[i] == 1) || (sum < 0 && a[i] == -1))) {
			flag[i - 1] = 1; flag[i] = 1;
			j += 2;
		}
	}
	if (j != bck) cout << -1 << endl;
	else {
		vector<pii> ans;
		for (int i = 1; i <= n; i++) {
			if (flag[i]) {
				ans.push_back({i, i + 1});
				i++;
			} else {
				ans.push_back({i, i});
			}
		}
		cout << ans.size() << endl;
		for (auto &x : ans) cout << x.fi << " " << x.se << endl;
	}
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		int sum = 0;
		vector<bool> flag(n + 1, false);
		rep(i, 1, n) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum == 0) {
			cout << n << endl;
			rep(i, 1, n) cout << i << " " << i << endl;
		} else if (sum % 2 != 0) {
			cout << -1 << endl;
		} else {
			solve(sum, flag);
		}
	}
	return 0;
}