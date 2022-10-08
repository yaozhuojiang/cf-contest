#include <bits/stdc++.h>
using namespace std;
#define mm(a,b) memset(a,b,sizeof(a))
const int N = 5;
const int M = (N << 2);
const int P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
class Solution {
public:
    long long dp[5][5][5][5][5][5][5], dp1[5][5][5][5][5][5][5];
    int Leetcode(vector<string>& words) {
        mm(dp, inf);
        mm(dp1, inf);
        int n = words.size();
        string t = "helloleetcode";
        set<char> se;
        for (auto &x : t) se.insert(x);
        map<char, int> mp;
        mp['h'] = 1;
        mp['e'] = 4;
        mp['l'] = 3;
        mp['o'] = 2;
        mp['t'] = 1;
        mp['c'] = 1;
        mp['d'] = 1;
        vector<vector<vector<int> > > pkg(30);
        for (int k = 0; k < words.size(); k++) {
            string x = words[k];
            int size = words[k].size();
            for (int i = 1; i <= (1 << size) - 1; i++) {
                string s = "";
                bool flag = true;
                map<char, int> cnt;
                for (int j = 0; j < size; j++) {
                    if ((i >> j) & 1) {
                        if (se.find(x[j]) == se.end()) flag = false;
                        s += "1";
                        cnt[x[j]]++;
                    }
                    else s += "0";
                }
                if (!flag) continue;
                string cao = s;
                int le = 0, ri = 0, cost = 0;
                s = "$" + s;
                int begin = 1, end = size;
                for (int aa = 1; aa <= size; aa++) {
                    if (s[aa] == '0') {
                        begin = aa;
                        break;
                    }
                }
                for (int aa = size; aa >= 1; aa--) {
                    if (s[aa] == '0') {
                        end = aa;
                        break;
                    }
                }
                string t = "";
                for (int aa = begin; aa <= end; aa++) t += s[aa];
                s = "$" + t;
                int bsize = size;
                size = t.size();
                for (int aa = 1; size - aa + 1 >= aa; aa++) {
                    int left = 0;
                    if (s[aa] == '1') {
                        left += (aa - 1 - le) * (size - aa - ri);
                        le++;
                    }
                    if (size - aa + 1 == aa) {
                        cost += left;
                        break;
                    }
                    if (s[size - aa + 1] == '1') {
                        left += (size - aa - le) * (aa - 1 - ri);
                        ri++;
                    }

                    if (s[aa] == '1') le--;
                    if (s[size - aa + 1] == '1') ri--;

                    int right = 0;
                    if (s[size - aa + 1] == '1') {
                        right += (size - aa - le) * (aa - 1 - ri);
                        ri++;
                    }
                    if (s[aa] == '1') {
                        right += (aa - 1 - le) * (size - aa - ri);
                        le++;
                    }
                    cost += min(left, right);
                    // if (k == 7 && s == "$11110") cout << left << " " << right << " " << cost <<  "" << le << " " << ri << endl;
                    // if (s[i] == '1') cost += (i - 1 - le) * (size - i - ri), le++;
                    // if (s[size - i + 1] == '1') cost += (size - i - le) * (i - 1 - ri), ri++;
                }
                // for (int i = 1; size - i >= i; i++) {
                //     if (s[i] == '1') cost += (i - le) * (size - 1 - i - ri), le++;
                //     if (s[size - i - 1] == '1') cost += (i - le) * (size - 1 - i - ri) ,ri++;
                // }
                size = bsize;
                vector<int> linshi;
                linshi.push_back(cnt['h']);
                linshi.push_back(cnt['e']);
                linshi.push_back(cnt['l']);
                linshi.push_back(cnt['o']);
                linshi.push_back(cnt['t']);
                linshi.push_back(cnt['c']);
                linshi.push_back(cnt['d']);
                linshi.push_back(cost);
                if (flag) {
                    // cout << k << " " << s << " " << cost << endl;
                    if (k == 5) cout << k << " " << cao << " " << t << " " << cost << endl;
                    pkg[k].push_back(linshi);
                }
            }
        }
        // for (int i = 0; i < words.size(); i++) cout << pkg[i].size() << endl;
        dp[0][0][0][0][0][0][0] = 0;
        dp1[0][0][0][0][0][0][0] = 0;
        // cout << dp[1][4][3][2][1][1][1] << endl;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < pkg[i].size(); j++) {
                for (int h1 = 1; h1 >= 0; h1--) {
                    for (int e1 = 4; e1 >= 0; e1--) {
                        for (int l1 = 3; l1 >= 0; l1--) {
                            for (int o1 = 2; o1 >= 0; o1--) {
                                for (int t1 = 1; t1 >= 0; t1--) {
                                    for (int c1 = 1; c1 >= 0; c1--) {
                                        for (int d1 = 1; d1 >= 0; d1--) {
if (h1 >= pkg[i][j][0] && e1 >= pkg[i][j][1] 
&& l1 >= pkg[i][j][2] && o1 >= pkg[i][j][3] 
&& t1 >= pkg[i][j][4] && c1 >= pkg[i][j][5] 
&& d1 >= pkg[i][j][6]) {
dp1[h1][e1][l1][o1][t1][c1][d1] = min(dp1[h1][e1][l1][o1][t1][c1][d1], dp[h1 - pkg[i][j][0]][e1 - pkg[i][j][1]][l1 - pkg[i][j][2]][o1 - pkg[i][j][3]][t1 - pkg[i][j][4]][c1 - pkg[i][j][5]][d1 - pkg[i][j][6]] + pkg[i][j][7]);
if (i == 6 && 
 h1 == 1 && e1 == 3 && l1 == 0 && o1 == 2 &&
 t1 == 0 && c1 == 0 && d1 == 1) cout << dp1[1][3][0][2][0][0][1] << endl;
// if (h1 == 1 && e1 == 4 && l1 == 3 && o1 == 2 && t1 == 1 && c1 == 1 && d1 == 1) cout << dp1[h1][e1][l1][o1][t1][c1][d1] << endl;
// if (dp1[1][3][3][2][1][1][1] == 5) cout << dp1[1][2][1][1][0][0][1] << endl;
}
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int h1 = 1; h1 >= 0; h1--) {
                for (int e1 = 4; e1 >= 0; e1--) {
                    for (int l1 = 3; l1 >= 0; l1--) {
                        for (int o1 = 2; o1 >= 0; o1--) {
                            for (int t1 = 1; t1 >= 0; t1--) {
                                for (int c1 = 1; c1 >= 0; c1--) {
                                    for (int d1 = 1; d1 >= 0; d1--) {
    dp[h1][e1][l1][o1][t1][c1][d1] = dp1[h1][e1][l1][o1][t1][c1][d1];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (dp1[1][4][3][2][1][1][1] >= inf) {
            // cout << -1 << endl;
            return -1;
        } else {
            return dp1[1][4][3][2][1][1][1];
        }
    }
};

// [
//     "puoube",   e
// "ooyroohy",     o o 
// "digj",  
// "hbsi",   h
// "iztdk",
// "dzpgkeu", d e
// "fhvtew", e
// "lltea",  l l t e
// "onlequ",
// "svgvg",
// "qldnydmp",
// "koldxhit",
// "yh",
// "ogsnllt", 
// "hc",
// "cg", c
// "sioi",
// "lczvch", l
// "ug"
// ]