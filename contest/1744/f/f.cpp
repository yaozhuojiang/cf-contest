#include<bits/stdc++.h>
#pragma GCC optimize(2)

#define mm(a,b) memset(a,b,sizeof(a))
#define ACCELERATE (ios::sync_with_stdio(false),cin.tie(0))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<long long,long long>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define rush() int T;cin>>T;while(T--)
#define sc(a) cin>>a
#define sc2(a,b) cin>>a>>b
#define sc3(a,b,c) cin>>a>>b>>c
#define pf(a) cout<<a<<endl
#define pf2(a,b) cout<<a<<" "<<b<<endl
#define pf3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define debug(x) cout<<#x<<": "<<x<<endl
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define PI acos(-1.0)
#define E exp(1.0)
#define ll long long
#define int long long
#define ld long double
#define ull unsigned long long
//#define io
using namespace std;

const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

//#define gc getchar
char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
inline int read(){
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}

const int maxn = 2e5+10;

int p[maxn], pos[maxn];

int32_t main(){
    #ifdef io
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    rush(){
        int n;
        sc(n);
        rep(i,1,n) { sc(p[i]), pos[p[i]] = i; }
		// pos[n] = 0;
        int l = pos[0], r = pos[0];
        int ans = 1;
        rep(x,1,n - 1){
            if(pos[x] >=l && pos[x]<=r) continue;
            int mx = 2*x;
            if(mx >= r-l+1){
                if(pos[x] > r){
                    for(int j=r;j<pos[x];j++){
                        int L = max(1ll, j-mx+1);
                        ans += max(0ll, l-L+1ll);
                    }
                }else{
                    for(int j=pos[x]+1;j<=l;j++){
                        int R = min(n*1ll, j+mx-1);
                        ans += max(0ll, R-r+1ll);
                    }
                }
				l = min(l, pos[x]);
				r = max(r, pos[x]);
            }
        }
        pf(ans);
    }
    return 0;
}