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
const int N = 2e3 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
string s;
int dp[N][N];
int char2int(char c) { return c - 'a' + 1; }
int solve(int i, int j)
{
	if (dp[i][j] != -3) return dp[i][j];
	if (i == j) {
		// cout << i << " " << j << " " << char2int(s[i]) << endl;
		return dp[i][j] = char2int(s[i]);
	}
	int left = solve(i + 1, j), right = solve(i, j - 1), mid;
	// 先手必败
	if (left == -2 || right == -2) mid =  -1;
	// 先手必赢
	else if (left == -1 && right == -1) mid = -2;
	// 先手能赢
	else if (left == 0 && right == -1) mid = char2int(s[i]);
	else if (left == -1 && right == 0) mid = char2int(s[j]);
	else if (left == -1 && right > 0) {
		if (char2int(s[j]) < right) mid =  -1;
		else if (char2int(s[j]) > right) mid = -2;
		else mid = 0;
	} else if (left > 0 && right == -1) {
		if (char2int(s[i]) < left) mid = -1;
		else if (char2int(s[i]) > left) mid = -2;
		else mid = 0;
	} else if (left == 0 && right == 0) {
		mid = min(char2int(s[i]), char2int(s[j]));
	} else if (left > 0 && right > 0) {
		if (char2int(s[i]) < left || char2int(s[j]) < right) mid = -1;
		else if (char2int(s[i]) > left && char2int(s[j]) > right) mid = -2;
		else if (char2int(s[i]) == left || char2int(s[j]) == right) mid = 0;
		else mid = 0;
	}
	// cout << i << " " << j << " " << mid << endl;
	return dp[i][j] = mid;

}
int main()
{
	ACCELERATE;
	rush() {
		cin >> s;
		int n = s.size();
		rep(i, 1, n) rep(j, i, n) dp[i][j] = -3;
		s = '0' + s;
		int res = solve(1, n);
		if (res == -1) cout << "Alice" << endl;
		else if (res == -2 || res > 0) cout << "Bob" << endl;
		else if (res == 0) cout << "Draw" << endl;
	}	
	return 0;
}