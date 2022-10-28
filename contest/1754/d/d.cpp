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
const int N = 5e5 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, x, a[N];
int main()
{
	ACCELERATE;
	cin >> n >> x;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int left = a[1], cnt = 1;
	if (left >= x) {
		cout <<"Yes" << endl;
		return 0;
	}
	rep(i, 2, n) {
		if (a[i] == left) {
			cnt++;
		} else {
			if (cnt % (left + 1) != 0) {
				cout << "No" << endl;
				return 0;
			} else {
				left = left + 1;
				cnt = cnt / left;
				if (left >= x) {
					cout << "Yes" << endl;
					return 0;
				}
				if (a[i] > left) {
					i--;
				} else {
					cnt += 1;
				}
			}
		}
	}
	while (233) {
		if (cnt % (left + 1) != 0) {
			cout << "No" << endl;
			return 0;
		} else {
			left = left + 1;
			cnt = cnt / (left);
			if (left >= x) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	return 0;
}