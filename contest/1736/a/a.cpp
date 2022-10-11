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
const int N = 105;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[N], b[N];
int main()
{
	ACCELERATE;
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		int cnta = 0, cntb = 0;
		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
			if (a[i] == 1) cnta ++;
		}
		for (int i = 0; i < n; i ++ ) {
			cin >> b[i];
			if (b[i] == 1) cntb ++;
		}

		int res = abs(cnta - cntb);
		cout << res + 1 << endl;
	}

	
	return 0;
}