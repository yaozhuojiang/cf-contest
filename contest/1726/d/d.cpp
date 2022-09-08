#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
#include<set>
#include<cassert>
using namespace std;
using LL = long long;

struct DSU{
    vector<int> p;
    DSU(int n) : p(n + 1){
        iota(p.begin(), p.end(), 0);
    }

    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool same(int x, int y) { 
        return find(x) == find(y); 
    }

    bool merge(int x, int y){
        x = find(x), y = find(y);
        if (x == y) return false;
        p[y] = x;
        return true;
    }
};

int main(){
    
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int> > edge(m);
        vector<int> remain;
        string ans(m, '0');
        vector<vector<pair<int, int> > > g(n + 1);
        for(int i = 0; i < m; i++)
            cin >> edge[i].first >> edge[i].second;
        DSU dsu(n);
        for(int i = 0; i < m; i++){
            auto [a, b] = edge[i];
            if (dsu.merge(a, b)){
                g[a].push_back({b, i});
                g[b].push_back({a, i});
                ans[i] = '1';
				cout << i << " ";
            }
            else remain.push_back(i);
        }
		cout << endl;
        if (m == n + 2){
            set<int> s;
            for(auto x : remain)
                s.insert(edge[x].first), s.insert(edge[x].second);
            if (s.size() == 3){
                ans[remain[0]] = '1';
				cout << remain[0] << endl;
                int p = edge[remain[0]].first;
				cout << "p " << p << endl;
                for(auto [to, id] : g[p]) {
					cout << id << endl;
					ans[id] = '0';
				}
            }
        }
        cout << ans << '\n';
    }

}