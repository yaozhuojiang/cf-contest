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
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		// if (n == 4) cout << "2 1 3 4";
		 if (n % 2 == 0) {
			// for (int i = n - 2; i >= 1; i--) cout << i << " ";
			for (int i = 1, j = n - 2, k = 0; k < n - 2; k += 2, i++, j--) cout << j << " " << i << " ";
			for (int i = n - 1; i <= n; i++) cout << i << " ";
		} else {
			if (n % 3 == 2) rep(i, 1, n) cout << i << " ";
			else if (n % 3 == 1) {
				rep(i, 1, n - 4) cout << i << " ";
				per(i, n - 2, n - 3) cout << i << " ";
				rep(i, n - 1, n) cout << i << " ";
			} else {
				rep(i, 1, n - 6) cout << i << " ";
				per(i, n - 4, n - 5) cout << i << " ";
				per(i, n - 2, n - 3) cout << i << " ";
				rep(i, n - 1, n) cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}