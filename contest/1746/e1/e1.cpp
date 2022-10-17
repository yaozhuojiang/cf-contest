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

string ans;
bool ask(int l, int r) {
	cout << "? " << r - l + 1 << " ";
	for (int i = l; i <= r; i ++ ) cout << i << " ";
	cout << endl;
	cout.flush();

	cin >> ans; 
	if (ans == "YES") return true;
	else return false;
}
bool guess(int n) {
	cout << "! " << n << endl;//<< endl << endl;
	cout.flush();
	
	cin >> ans;
	if (ans == ":)") return true;  // 回答NO，没骗我
	else return false;
}
int main()
{
	ACCELERATE;
	int n;
	cin >> n;
	// 如果只有一个数，不用猜了。。
	if (n == 1) {
		guess(n);
		return 0;
	}
	// 第一次强行猜测n
	ask(1, n - 1);
	// cin >> ans;

	// 不管他回答什么，都猜n！
	if (guess(n) == true) return 0;  // 猜对了直接结束
	// 猜错了，从1~n-1中猜测
	int l = 1, r = n - 1;
	while (l < r) {
		int mid = l + r >> 1;
		ask(l, mid);  // 随便问一下。。。
		if (ask(l, mid)) {  // 重复再问一遍，确保他说真话
			r = mid;
		}
		else l = mid + 1;
	}
	guess(l);  // 猜完就听天由命
	
	return 0;
}