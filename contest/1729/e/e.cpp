#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, x[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	stack<int> stk;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		stk.push(x[i]);
		if (stk.top() == x[i]) {
			if (stk.top() == 0) cnt--;
			stk.pop();
			stk.push(x[i] + 1);
			if (x[i] + 1 == 0) cnt++;
		}
		if (stk.top() < 0) {
			int tmp = stk.top();
			if (tmp == 0) cnt--;
			stk.pop();
			stk.push(x[i] + tmp);
			if (x[i] + tmp == 0) cnt++;
		}
		if (x[i] == 0 && cnt) {
			vector<int> v;
			while (stk.top() != 0) {
				v.push_back(stk.top());
				stk.pop();
			}
			stk.pop();
			cnt--;
		}
	}
	while (!stk.empty())
		
	return 0;
}