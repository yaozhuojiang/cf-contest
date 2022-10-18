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
const int N = 1e6 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n;
string s;
int main()
{
	ACCELERATE;
	cin >> n >> s;
	s = '$' + s;
	string t = "$";
	rep(i, 1, n) {
		if (s[i] == '1') {
			rep(j, i, n) t += s[j];
			break;
		}
	}
	if (t == "$") cout << 0 << endl;
	else {
		int tn = t.size() - 1;
		string b = "$";
		rep(i, 1, tn) {
			if (t[i] == '0') {
				rep(j, i, tn) {
					b += t[j];
				}
				break;
			}
		}
		if (b == "$") {
			string ans = "";
			rep(i, 1, tn) ans += t[i];
			cout << ans << endl;
		} else {
			int bn = b.size() - 1;
			string ans = "";
			rep(i, 1, tn) {
				if (t[i] == '0') break;
				string now = "";
				for (int j = i, k = 1; k <= bn; k++, j++) now.push_back((t[j] == '1' || b[k] == '1') ? '1' : '0');
				if (now > ans) ans = now;
			}
			rep(i, 1, tn) {
				if (t[i] == '0') {
					cout << ans << endl;
					break;
				} else cout << t[i];
			}
		}
	}
	return 0;
}