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
string s;
int n, pre[N];
int f[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int a, int b)
{
	int x = find(a), y = find(b);
	if (x != y) f[y] = x;
}
int main()
{
	ACCELERATE;
	rush() {
		cin >> n >> s;
		s = '0' + s;
		stack<int> stk;
		rep(i, 1, 2 * n) f[i] = i;
		rep(i, 1, 2 * n) {
			if (s[i] == '(') stk.push(i);
			else if (s[i] == ')') {
				int idx = stk.top();
				merge(idx, i);
				// cout << idx << " " << i << endl;
				stk.pop();
				if (s[idx - 1] == ')') {
					merge(idx - 1, i);
					// cout << idx - 1 << " " << i << endl;
				}
			}
		}
		set<int> se;
		rep(i, 1, 2 * n) se.insert(find(i));
		cout << se.size() << endl;
	}
	return 0;
}