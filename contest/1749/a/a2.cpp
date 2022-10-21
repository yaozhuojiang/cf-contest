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
const int N = 15;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int rook[N][N];
int g[N][N];
int n, m;

bool check(int x, int y) {
	int flag = 0;

	if (!rook[x - 1][y]){
		for (int i = 1; i <=n; i ++ ) 
			if (rook[x-1][i]) {
				flag = 1;
				break;
			}
		if (!flag) return true;
	}
	

	if (!rook[x + 1][y]){
		for (int i = 1; i <=n; i ++ ) 
			if (rook[x+1][i]) {
				flag = 1;
				break;
			}
		if (!flag) return true;
	}

	if (!rook[x][y-1]){
		for (int i = 1; i <=n; i ++ ) 
			if (rook[i][y-1]) {
				flag = 1;
				break;
			}
		if (!flag) return true;
	}

	if (!rook[x][y+1]){
		for (int i = 1; i <=n; i ++ ) 
			if (rook[i][y+1]) {
				flag = 1;
				break;
			}
		if (!flag) return true;
	}

	return false;
}
int main()
{
	ACCELERATE;
	rush(){
		cin >> n >> m;
		
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			rook[a][b] = 1;
		}

		if (m == n) cout << "NO" << endl;
		else cout << "YES" << endl;


	}
	
	return 0;
}