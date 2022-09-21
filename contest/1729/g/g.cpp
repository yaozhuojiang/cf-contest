#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, height[N], dist[N], suf[N], stk[N], hh, tt = -1;
int main()
{
	cin >> n;
	string s;
	cin >> s;
	int size = s.size();
	int tmp = 0, tot = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] == ',' || i == size - 1) {
			if (i == size - 1) tmp = tmp * 10 + (s[i] - '0');
			height[++tot] = tmp;
			tmp = 0;
		} else tmp = tmp * 10 + (s[i] - '0');
	}
	cin >> s;
	size = s.size();
	tmp = 0, tot = 1;
	for (int i = 0; i < size; i++) {
		if (s[i] == ',' || i == size - 1) {
			if (i == size - 1) tmp = tmp * 10 + (s[i] - '0');
			dist[++tot] = tmp;
			tmp = 0;
		} else tmp = tmp * 10 + (s[i] - '0');
	}
	for (int i = 2; i <= n; i++) suf[i] = suf[i - 1] + dist[i];
	stk[++tt] = 1;
	int idx = 1, ans = 0;
	for (int i = 2; i <= n; i++) {
		bool flag = true;
		while (hh <= tt && stk[tt] > height[i]) {
			if (flag) {
				idx = stk[tt];
				ans++;
				flag = false;
			}
			tt--;
		}
		while (hh <= tt && stk[hh] <= idx) tt++;
		flag = true;
		while (hh <= tt && suf[i] - suf[idx] > 100) {
			ans++;
			idx = stk[tt];
			break;
		}
		while (hh <= tt && stk[hh] <= idx) tt++; 
		stk[++tt] = i;
	}
	cout << ans << endl;
	return 0;
}
