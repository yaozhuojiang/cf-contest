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
const int N = 55;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[N];
int Hash[N];
int main()
{
	ACCELERATE;
	rush(){
		memset(Hash, 0, sizeof(Hash));
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++ ) {
			cin >> a[i];
		}
		string s;
		cin >> s;

		// int k = 0;
		int flag = 0;
		for (int i = 0; i < n; i ++ ) {
			if (Hash[a[i]] == 0) {
				Hash[a[i]] = s[i];
			}
			else {
				if (Hash[a[i]] != s[i]) {
					cout << "NO" << endl;
					flag = 1;
					break;
				}
			}
		}
		if (!flag) cout << "YES" << endl;

	}
	
	return 0;
}