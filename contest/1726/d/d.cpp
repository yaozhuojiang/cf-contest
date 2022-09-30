// #include<iostream>
// #include<cstring>
// #include<vector>
// #include<numeric>
// #include<set>
// #include<cassert>
// using namespace std;
// using LL = long long;

// struct DSU{
//     vector<int> p;
//     DSU(int n) : p(n + 1){
//         iota(p.begin(), p.end(), 0);
//     }

//     int find(int x){
//         return p[x] == x ? x : p[x] = find(p[x]);
//     }

//     bool same(int x, int y) { 
//         return find(x) == find(y); 
//     }

//     bool merge(int x, int y){
//         x = find(x), y = find(y);
//         if (x == y) return false;
//         p[y] = x;
//         return true;
//     }
// };

// int main(){
    
//     cin.tie(0);
//     cout.tie(0);
//     ios::sync_with_stdio(0);

//     int T;
//     cin >> T;
//     while(T--){
//         int n, m;
//         cin >> n >> m;
//         vector<pair<int, int> > edge(m);
//         vector<int> remain;
//         string ans(m, '0');
//         vector<vector<pair<int, int> > > g(n + 1);
//         for(int i = 0; i < m; i++)
//             cin >> edge[i].first >> edge[i].second;
//         DSU dsu(n);
//         for(int i = 0; i < m; i++){
//             auto [a, b] = edge[i];
//             if (dsu.merge(a, b)){
//                 g[a].push_back({b, i});
//                 g[b].push_back({a, i});
//                 ans[i] = '1';
// 				cout << i << " ";
//             }
//             else remain.push_back(i);
//         }
// 		cout << endl;
//         if (m == n + 2){
//             set<int> s;
//             for(auto x : remain)
//                 s.insert(edge[x].first), s.insert(edge[x].second);
//             if (s.size() == 3){
//                 ans[remain[0]] = '1';
// 				cout << remain[0] << endl;
//                 int p = edge[remain[0]].first;
// 				cout << "p " << p << endl;
//                 for(auto [to, id] : g[p]) {
// 					cout << id << endl;
// 					ans[id] = '0';
// 				}
//             }
//         }
//         cout << ans << '\n';
//     }

// }

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
int n, m, f[N], re[N], ans[N];
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
        cin >> n >> m;
        vector<pii> e;
        rep(i, 1, n) f[i] = i;
        rep(i, 1, m) {
            int u, v;
            cin >> u >> v;
            e.push_back({u, v});
        }
        rep(i, 0, m - 1) ans[i] = 0;
        vector<int> re;
        vector<vector<pii> > g(n + 1);
        rep(i, 0, m - 1) {
            int l = find(e[i].first), r = find(e[i].second);
            if (l != r) {
                ans[i] = 1;
                merge(l, r);
                int u = e[i].first, v = e[i].second;
                g[u].push_back({v, i});
                g[v].push_back({u, i});
            } else re.push_back(i);
        }
        if (m == n + 2) {
            set<int> s;
            for (auto &x : re) s.insert(e[x].first), s.insert(e[x].second);
            if (s.size() == 3) {
                ans[re[0]] = 1;
                for (auto &x : g[e[re[0]].first]) ans[x.second] = 0;
            }
        }
        rep(i, 0, m - 1) cout << ans[i];
        cout << endl;
    }
    return 0;
}