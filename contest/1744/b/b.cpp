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
const int N = 1e5 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[N];
int main()
{
	ACCELERATE;
	rush() {
		int n, q;
		long long sum = 0;
		int odd = 0, even = 0;
		cin >> n >> q;
		for(int i = 0; i < n; i ++ ) {
			cin >> a[i];
			sum += a[i];
			if (a[i] % 2 == 0) even ++;
			else odd ++;
		}
		while (q -- ) {
			int op, x;
			cin >> op >> x;
			if (op == 0) {
				sum += even * x;
				cout << sum << endl;
				// 原来是偶数，加上奇数，全部变奇数
				if (x % 2 == 1) {
					odd += even;
					even = 0;
				}
			}
			else { // == 1
				sum += odd * x;
				cout << sum << endl;
				// 原来是奇数，加上奇数，全部变偶数
				if (x % 2 == 1) {
					even += odd;
					odd = 0;
				}
			}
		}
	}
	
	return 0;
}