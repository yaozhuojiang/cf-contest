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
int a, b, ab, c, d;
vector<pii> ab_val;
map<int, int> mp;
void divide(int x)
{
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) {
			int c = 0;
			while (x % i == 0) {
				c++;
				x /= i;
			}
			mp[i] += c;
		}
	}
	if (x > 1) mp[x] += 1;
}
bool output;
void dfs(int idx, int left)
{
	if (output) return ;
	if (idx == ab_val.size()) {
		int right = ab / left;
		int x = (a / left) * left;
		if (x <= a) x += left;
		int y = (b / right) * right;
		if (y <= b) y += right;
		if (x <= c && y <= d) {
			cout << x << " " << y << endl;
			output = true;
		}
		return ;
	}
	int prime = ab_val[idx].first, cnt = ab_val[idx].second;
	rep(i, 0, cnt) {
		dfs(idx + 1, left);
		left *= prime;
	}
}
int32_t main()
{
	ACCELERATE;
	rush() {
		cin >> a >> b >> c >> d;
		ab = a * b;
		mp.clear();
		ab_val.clear();
		output = false;
		divide(a);
		divide(b);
		for (auto &x : mp) ab_val.push_back({x.first, x.second});
		dfs(0, 1);
		if (!output) cout << -1 << " " << -1 << endl;
	}
	return 0;
}