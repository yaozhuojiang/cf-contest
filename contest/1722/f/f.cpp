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
const int N = 2e2 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, id[N][N];
char grid[N][N];
bool check(int r, int c, int x, int y, int f)
{
	if (r == 0 && c == 0) y--;
	if (grid[x + r][y + c] != '.') return true;
	rep(i, 0, 1) rep(j, 0, 1) {
		if (i == r && j == c) continue;
		if (grid[x + i][y + j] != '*') return true;
	}
	if (f == 1) r--, c--;
	if (f == 2) r--, c++;
	if (f == 3) r++, c--;
	if (f == 4) r++, c++;
	rep(i, -1, 2) rep(j, -1, 2) {
		if (i == r && j == c) continue;
		if (x + i < 0 || x + i > n + 1 || y + j < 0 || y + j > m + 1) continue;
		if (i!= -1 && i != 2 && j != -1 && j != 2) continue;
		if (grid[x + i][y + j] == '*') return false;
	}
	if (f == 1) r++, c++;
	if (f == 2) r++, c--;
	if (f == 3) r--, c++;
	if (f == 4) r--, c--;
	rep(i, 0, 1) rep(j, 0, 1) {
		if (i == r && j == c) continue;
		if (grid[x + i][y + j] == '*') id[x + i][y + j] = f;
	}
	return true;
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> m;
		rep(i, 0, n + 1) rep(j, 0, m + 1) grid[i][j] = '.', id[i][j] = 0;
		rep(i, 1, n) rep(j, 1, m) cin >> grid[i][j];
		bool flag = true;
		rep(i, 1, n) rep(j, 1, m) {
			if (grid[i][j] == '*' && !id[i][j]) {
				rep(x, 0, 1) rep(y, 0, 1) {
					check(x, y, i, j, x * 2 + y + 1);
				}
				if (id[i][j] == 0) flag = false;
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}