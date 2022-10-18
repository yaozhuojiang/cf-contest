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
string s;
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> s;
		s = '$' + s;
		rep(i, 1, n) cin >> a[i];
		vector<int> ve;
		int cnt = 0, ans = 0;
		rep(i, 1, n) {
			if (s[i] == '1') {
				cnt++;
				if (i - 1 >= 1 && s[i - 1] == '0') ve.push_back(a[i - 1]);
				ve.push_back(a[i]);
			}
			if (s[i] == '0' || i == n) {
				if (cnt) {
					sort(ve.begin(), ve.end());
					int tmp = 0;
					for (int k = ve.size() - 1, j = 0; j < cnt; j++, k--) tmp += ve[k];
					ans += tmp;
					ve.clear();
				}
				cnt = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}