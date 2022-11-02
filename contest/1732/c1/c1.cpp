#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define db double
#define int long long
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
int n, q, a[N], b[N], idx[N], L[N], R[N], cnt[N][35], tmp[N];
ll suf[N], xxx[N];
int32_t main()
{
	ACCELERATE;
	rush() {
		int tot = 0;
		b[0] = -1;
		cin >> n >> q;
		rep(i, 1, n) {
			cin >> b[i];
			if (b[i]) {
				a[++tot] = b[i];
				idx[tot] = i;
			} else {
				if (b[i - 1] != 0) {
					a[++tot] = b[i];
					idx[tot] = i;
				}
			}
		}
		a[++tot] = 0;
		idx[tot] = n + 1;
		rep(i, 1, tot) {
			suf[i] = a[i] + suf[i - 1];
			xxx[i] = a[i] ^ xxx[i - 1];
		}
		// per(i, 30, 0) cout << cnt[i] << " ";
		// cout << endl;
		rep(i, 1, q) {
			cin >> L[i] >> R[i];
			ll ans = 0;
			int left = L[i], right = L[i];
			int pos1 = lower_bound(idx + 1, idx + tot + 1, L[i]) - idx;
			int pos2 = lower_bound(idx + 1, idx + tot + 1, R[i]) - idx;
			if (idx[pos2] > R[i]) pos2--;
			for (int j = pos1; j <= min(pos1 + 30ll, pos2); j++) {
				per(k, 30, 0) tmp[k] = cnt[pos2][k] - cnt[j - 1][k];
				bool flag = false;
				per(k, pos2, j + 1) {
					int pre = xxx[k - 1] ^ xxx[j - 1];
					if ((pre ^ a[k]) - pre < a[k]) {
						ll woc = suf[k] - suf[j - 1] - (xxx[k] ^ xxx[j - 1]);
						if (woc > ans) {
							ans = woc;
							left = idx[j], right = idx[k];
						} else if (woc == ans && idx[k] - idx[j] < right - left) {
							left = idx[j], right = idx[k];
						}
						flag = true;
						break;
					}
				}
			}
			cout << left << " " << right << endl;
		}
	}
	return 0;
}