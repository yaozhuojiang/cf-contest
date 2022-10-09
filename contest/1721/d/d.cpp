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
int n, a[2][N];
int solve(int le, int ri, int i, int id)
{
	int l = le, r = ri;
	if (id) {
		while (le < ri) {
			while (le <= r && (a[id][le] >> i) & 1) le++;
			while (ri >= l && !((a[id][ri] >> i) & 1)) ri--;
			if (le < ri) swap(a[id][le], a[id][ri]);
		}
	} else {
		while (le < ri) {
			while (le <= r && !((a[id][le] >> i) & 1)) le++;
			while (ri >= l && (a[id][ri] >> i) & 1) ri--;
			if (le < ri) swap(a[id][le], a[id][ri]);
		}
	}
	int cnt = 0;
	rep(j, l, r) {
		if (((a[id][j] >> i) & 1) == id) cnt++;
		else break;
	}
	return cnt;
}
int main()
{
	ACCELERATE;
	rush() {
		int n;
		cin >> n;
		rep(i, 1, n) cin >> a[0][i];
		rep(i, 1, n) cin >> a[1][i];
		int ans = 0;
		multiset<int> se;
		se.insert(1);
		se.insert(n);
		per(i, 30, 0) {
			int left = -1, right = -1;
			vector<int> ve;
			bool flag = true;
			for (auto &x : se) {
				if (left == -1) left = x;
				else if (right == -1) {
					right = x;
					int zero = solve(left, right, i, 0), one = solve(left, right, i, 1);
					// cout << i << " " << left << " " << right << " " << zero << " " << one << endl;
					// if (i <= 4) cout << i << " " << zero << " " << one << endl;
					if (zero != one) {
						flag = false;
						break;
					} else {
						if (zero == 0 || zero == right - left + 1) {
							left = right = -1;
							continue;
						}
						ve.push_back(left + zero - 1);
						ve.push_back(left + zero);
					}
					left = right = -1;
				}
			}
			// if (i <= 4) {
			// 	cout << i << endl;
			// 	rep(j, 1, n) cout << a[0][j] << " ";
			// 	cout << endl;
			// 	rep(j, 1, n) cout << a[1][j] << " ";
			// 	cout << endl;
			// }
			if (flag) {
				for (auto &x : ve) se.insert(x);
				ans |= (1 << i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}