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

int a[2005];

int main()
{
	ACCELERATE;
	
	rush(){
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++){
			cin>>a[i];
		}
		if(n==1) {
			cout<<0<<endl;
			continue;
		}
		int ma = -1, maxcha = -1e9;  // a[]最大值、前一个减后一个的差最大值
		for (int i = 0; i < n-1; i++){
			int cha = a[i] - a[i+1];
			maxcha = max(maxcha, cha);

			ma = max(ma, a[i]);
		}
		ma = max(ma, a[n-1]);
		maxcha = max(maxcha, a[n-1]-a[0]);

		cout<<ma<<' '<<maxcha<<' '<<a[0]<<endl;
		

		cout << max(ma-a[0], maxcha) << endl;

	}

	return 0;
}