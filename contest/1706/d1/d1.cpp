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
const int N = 3e3 + 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, k, a[N];
int main()
{
    ACCELERATE;
    rush() {
        cin >> n >> k;
        rep(i, 1, n) cin >> a[i];
        int ans = N;
        rep(i, 0, a[1]) {
            int mx = i;
            rep(j, 1, n) {
                int p = min(k, i ? a[j] / i : k);
                mx = max(mx, a[j] / p);
            }
            ans = min(ans, mx - i);
        }
        cout << ans << endl;
    }
    return 0;
}