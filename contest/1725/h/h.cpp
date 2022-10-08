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
int main()
{
	ACCELERATE;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	int zero = 0, one = 0;
	rep(i, 1, n) {
		if ((a[i] % 3) * (a[i] % 3) == 0) {
			a[i] = 0;
			zero++;
		} else {
			a[i] = 1;
			one++;
		}
	}
	if (zero == 0 || one == 0) {
		cout << 1 << endl;
		rep(i, 1, n / 2) cout << 1;
		rep(i, n / 2 + 1, n) cout << 0;
		cout << endl;
	} else if (zero <= n / 2) {
		cout << 0 << endl;
		int c = n / 2 - zero;
		rep(i, 1, n) {
			if (a[i] == 0) cout << 0;
			else {
				if (c) {
					cout << 0;
					c--;
				} else {
					cout << 1;
				}
			}
		}
		cout << endl;
	} else {
		cout << 2 << endl;
		int c = n / 2 - one;
		rep(i, 1, n) {
			if (a[i] == 1) cout << 1;
			else {
				if (c) {
					cout << 1;
					c--;
				} else {
					cout << 0;
				}
			}
		}
		cout << endl;
	}
	return 0;
}