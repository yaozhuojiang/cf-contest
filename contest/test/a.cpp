#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
string s1, s2;
int len1, len2, p[N];
void init()
{
    s2 = "^#";
    for (int i = 0; i < len1; i++) s2 += s1[i], s2 += "#";
    len2 = len1 * 2 + 2;
}
void manacher()
{
    int mx = 0, id = 0;
    for (int i = 0; i < len2; i++) {
        if (i < mx) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        while (s2[i + p[i]] == s2[i - p[i]]) p[i]++;
        if (mx < i + p[i]) mx = i + p[i], id = i;
    }
}
int main()
{
    cin >> s1;
    init();
    manacher();
    return 0;
}


// 朴素写法
// 枚举i和j
// class Solution {
// public:
//     bool safe(int x, int y, string &s)
//     {
//         for (int i = x, j = y; i < j; i++, j--) if (s[i] != s[j]) return false;
//         return true;
//     }
//     int getLongestPalindrome(string A) {
//         int n = A.size(), ans = 1;
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (safe(i, j, A)) ans = max(ans, j - i + 1);
//             }
//         }
//         return ans;
//     }
// }

// 进阶要求解法，马拉车算法
class Solution {
public:
    int p[N];
    void init()
    {
        s2 = "^#";
        for (int i = 0; i < len1; i++) s2 += s1[i], s2 += "#";
        len2 = len1 * 2 + 2;
    }
    void manacher()
    {
        int mx = 0, id = 0;
        for (int i = 0; i < len2; i++) {
            if (i < mx) p[i] = min(p[2 * id - i], mx - i);
            else p[i] = 1;
            while (s2[i + p[i]] == s2[i - p[i]]) p[i]++;
            if (mx < i + p[i]) mx = i + p[i], id = i;
        }
    }
    int getLongestPalindrome(string A) {
        init();
        manacher();
    }
};