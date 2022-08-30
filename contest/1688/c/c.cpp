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
int tr(char c) { return c - 'a'; }
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		string s, t;
		vector<string> se;
		vector<int> cnt(30, 0), num(30, 0);
		rep(i, 1, 2 * n) {
			cin >> s;
			for (auto &c : s) cnt[tr(c)]++;
			se.emplace_back(s);
		}
		cin >> t;
		for (auto &c : t) num[tr(c)]++;
		rep(i, 0, 25) {
			cnt[i] -= num[i];
			if (cnt[i] % 2) {
				cout << char(i + 'a') << endl;
				break;
			}
		}
	}	
	return 0;
}