#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, dp[N][N];
string a, b;
int main()
{
	cin >> n >> m >> a >> b;
	a = '0' + a;
	b = '0' + b;
	int ans = 0;
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > ans) {
					ans = dp[i][j];
					v.clear();
					v.push_back({i, ans});
				} else if (dp[i][j] == ans) {
					v.push_back({i, ans});
				}
			}
			else dp[i][j] = 0;
		}
	}
	vector<string> res;
	for (auto &x : v) {
		int l = x.first - x.second + 1, r = x.first;
		string tmp = "";
		for (int i = l; i <= r; i++) tmp += a[i];
		res.push_back(tmp);
	}
	sort(res.begin(), res.end());
	if (ans >= 2) cout << res[0] << endl;
	else cout << 0 << endl;
	return 0;
}