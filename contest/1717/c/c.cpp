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
const int N = 4e5 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, a[N], b[N];
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		rep(i, 1, n) {
			cin >> a[i];
			a[i + n] = a[i];
		}
		rep(i, 1, n) {
			cin >> b[i];
			b[i + n] = b[i];
		}
		bool flag = true;
		rep(i, 1, n) if (a[i] > b[i]) flag = false;
		rep(i, 1, n) if (b[i] - b[i + 1] >= 2 && a[i] < b[i]) flag = false;
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}