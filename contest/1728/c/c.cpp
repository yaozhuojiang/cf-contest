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


unordered_map<int, int> a,b;

int f(int x){
	int res = 0;
	while(x){
		res ++;
		x /= 10;
	}
	return res;
}

int main()
{
	ACCELERATE;
	rush(){
		int cnt= 0;
		a.clear();
		b.clear();

		int n;
		cin>>n;
		

		for (int i=0; i<n;i++) {
			int x;
			cin>>x;
			if(!a.count(x)) a[x] = 1;
			else a[x] ++;
		}
		for (int i=0; i<n;i++) {
			int x;
			cin>>x;
			if(!b.count(x)) b[x] = 1;
			else b[x] ++;
		}

		//将大于10的变掉
		for (auto it = a.begin(); it != a.end(); it++){
			auto y = b.find(it->first);
			while(y != b.end() && it->second && y->second){
				(it->second) --;
				(y->second) --;
			}
			if(it->first >= 10){
				int newn = f(it->first);  
				cnt++;
				if (!a.count(newn)) a[newn] = 1;
				else a[newn] ++;

				a[it->first] = 0;
			}
		}

		cout<<"去掉a中大于10："<<cnt<<endl;

		for (auto it = b.begin(); it != b.end(); it++){
			auto x = a.find(it->first);
			while(x != a.end() && it->second && x->second){
				(it->second) --;
				(x->second) --;
			}
			if(it->first >= 10){
				int newn = f(it->first);
				cnt++;
				if (!a.count(newn)) a[newn] = 1;
				else a[newn] ++;

				b[it->first] = 0;
			}
		}

		cout<<"去掉b中大于10："<<cnt<<endl;

		//现在只剩下个位数了
		for (auto it = a.begin(); it != a.end(); it++){
			auto y = b.find(it->first);
			while(y != b.end() && it->second && y->second){
				(it->second) --;
				(y->second) --;
			}
		}

		// for (auto it = b.begin(); it != b.end(); it++){
		// 	auto x = a.find(it->first);
		// 	while(x != a.end() && it->second && x->second){
		// 		(it->second) --;
		// 		(x->second) --;
		// 	}
		// }


		//剩下的都是没法匹配的，要全部变成1，直接计算
		for (auto it = a.begin(); it != a.end(); it++){
			if(it -> second){
				cnt++;
			}
		}
		cout<<"去掉a中剩下的个位数："<<cnt<<endl;
		for (auto it = b.begin(); it != b.end(); it++){
			if(it -> second){
				cnt++;
			}
		}


		cout << cnt<<endl;


		


	}

	return 0;
}