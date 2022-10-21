#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int inf = 0x3f3f3f3f;
int n;
char mp[N][N];
int dist[N][N];
int ndir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main()
{
    cin >> n;
    memset(dist, inf, sizeof(dist));
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'C') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto frt = q.front(); q.pop();
        int x = frt.first, y = frt.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + ndir[i][0], ny = y + ndir[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && mp[nx][ny] == 'A') {
                if (dist[nx][ny] == inf) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == 'A') {
                ans += (dist[i][j] == inf ? 0 : dist[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
3
A B C
A A A
A A C

4
A B C C
B A B C
B B A C
A C B C

*/