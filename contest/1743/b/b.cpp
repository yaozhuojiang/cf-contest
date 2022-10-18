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
const int N = 50 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[120];
int main()
{
	ACCELERATE;
	rush(){
		int n;
		cin >> n;
		
		for (int i = 1; i <= n ; i ++) {
			a[i] = i + 1 >> 1;
			if (i % 2 == 0) a[i] = i / 2 + (n + 1) / 2;

		}
		swap(a[n], a[n-2]);
		for (int i = 1; i <= n; i ++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}