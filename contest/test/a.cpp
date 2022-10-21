#include <bits/stdc++.h>
using namespace std;
const int N = 25;
bool vis[N][N];
int m, n, k, board[N][N], dis[N][N], bx, by, ex, ey;
int ndir[][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int main()
{
    bool chck = true;
    cin >> m >> n >> k;
    if (m <= 0 || m > 20 || n < 0 || n > 20 || k <= 0 || k > m * n) chck = false;
    vector<vector<pair<int, int> > >f(m + 1, vector<pair<int, int> >(n + 1, {-1, -1}));
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        if (x < 0 || x >= m || y < 0 || y >= n) {
            chck = false;
        }
        vis[x][y] = 1;
        board[x][y] = 1;
    }
    cin >> bx >> by >> ex >> ey;
    if (bx < 0 || bx >= m || by < 0 || by >= n || ex < 0 || ex >= m || ey < 0 || ey >= n) {
        chck = false;
    }
    if (!chck) {
        cout << 0 << endl;
        return 0;
    }
    queue<pair<int, int> > q;
    q.push({bx, by});
    vis[bx][by] = 1;
    board[bx][by] = 0;
    bool flag = false;
    while (!q.empty()) {
        auto frt = q.front(); q.pop();
        int cx = frt.first, cy = frt.second;
        // cout << "### " << cx << " " << cy << " " << dis[cx][cy] << endl;
        if (cx == ex && cy == ey) {
            vector<pair<int, int> > ans;
            cout << dis[ex][ey] << endl;
            while (f[ex][ey].first != -1 && f[ex][ey].second != -1) {
                ans.push_back({ex, ey});
                int a = f[ex][ey].first, b = f[ex][ey].second;
                ex = a, ey = b;
            }
            reverse(ans.begin(), ans.end());
            for (auto &x : ans) {
                cout << x.first << " " << x.second << endl;
            }
            flag = true;
            break;
        }
        for (int i = 0; i < 8; i++) {
            int nx = cx + ndir[i][0], ny = cy + ndir[i][1];
            bool has = false;
            while (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 1) {
                has = true;
                nx = nx + ndir[i][0], ny = ny + ndir[i][1];
            }
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && has && !vis[nx][ny]) {
                f[nx][ny] = {cx, cy};
                dis[nx][ny] = dis[cx][cy] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (!flag) cout << 0 << endl;
    return 0;
}
/*
5 7 9
1 2
1 4
2 1
2 3
2 5
3 3
4 2
4 3
4 4
4 2
0 4

6 7 9
1 2
1 4
2 1
2 3
2 5
3 3
4 2
4 3
4 4
4 4
0 3


6 6 11
1 2
1 4
2 1
2 2
2 3
2 5
3 3
4 2
4 3
4 4
5 3
4 4
1 5


*/