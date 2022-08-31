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
int main()
{
	ACCELERATE;
	rush() {
		cin >> n;
		vector<int> v1, v2;
		if (n % 4 == 1) v1.push_back(0);
		else if (n % 4 == 2) {
			v1.push_back(2); v1.push_back(3); v1.push_back(4);
			v2.push_back(1); v2.push_back(8); v2.push_back(12);
			n -= 6;
		}
		else if (n % 4 == 3) v1.push_back(1), v1.push_back(3), v2.push_back(2);
		int t = n / 4, i, j;
		for (i = (1 << 20), j = 0; j < 2 * t; j++, i++) v1.push_back(i);
		if (i & 1) i++;
		for (j = 0; j < 2 * t; j++, i++) v2.push_back(i);
		int ans1 = 0, ans2 = 0;
		while (!v1.empty() || !v2.empty()) {
			if (!v1.empty()) {
				cout << v1.back() << " ";
				ans1 ^= v1.back();
				v1.pop_back();
			}
			if (!v2.empty()) {
				cout << v2.back() << " ";
				ans2 ^= v2.back();
				v2.pop_back();
			}
		}
		cout << endl;
		// cout << "T " << ans1 << " " << ans2 << endl;
	}
	return 0;
}