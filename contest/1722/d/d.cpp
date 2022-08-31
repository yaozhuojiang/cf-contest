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
int n;
string s;
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> s;
		s = '0' + s;
		vector<int> v;
		ll ans = 0;
		rep(i, 1, n) {
			int left = i - 1, right = n - i;
			v.push_back(s[i] == 'L' ? max(0, right - left) : max(left - right, 0));
			ans += (s[i] == 'L' ? left : right);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for(auto &x : v) {
			ans += x;
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}