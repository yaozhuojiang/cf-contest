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
class Solution {
public:
	int _k;
	vector<int> _d;
	vector<vector<int> > _e;
	vector<vector<int> > grid(2);
	void tolo(int idx)
	{
		queue<int> q;
		for (int i = 1; i <= _k; i++) if (_d[i] == 0) q.push(i);
		while (!q.empty()) {
			auto frt = q.front(); q.pop();
			grid[idx].push_back(frt);
			for (auto &v : _e[frt]) {
				_d[v]--;
				if (_d[v] == 0) q.push(v);
			}
		}
		if (grid[idx].size() != k) return false;
		return true;
	}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
		_k = k;
		vector<vector<int> > e(k + 1);
		vector<int> d(k + 1, 0);
		for (auto &x : row) e[x[0]].push_back(x[1]), d[x[1]]++;
		_e = e;	_d = d;
		if (!tolo(0)) flag = false;
		e.clear(); d.clear();
		for (auto &x : col) e[x[0]].push_back(x[1]), d[x[1]]++;
		_e = e; _d = d;
		if (!tolo(1)) flag = false;
		if (!flag) return vector<int>();
		for (int i = 0; i < k; i++) r[grid[0][i]].first = i;
		for (int i = 0; i < k; i++) r[grid[1][i]].second = i;
		vector<vector<int>> ans(k, vector<int>(k, 0));
		for (int i = 1; i <= k; i++) ans[r[i].first][r[i].second] = i;
		return ans;
    }
};