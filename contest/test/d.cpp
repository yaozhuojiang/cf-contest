#include<bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

void solve(){
    int n;
    cin>>n;
    vector<int> hig(n+5);
    vector<int> dis(n+5);
    string s;

    cin>>s;
    s+=',';
    int tmp = 0;
    int len = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] != ','){
            tmp = tmp * 10 + s[i]-'0';
        }else{
            hig[++len] = tmp;
            tmp = 0;
        }
    }
    // hig[++len] = 101;

    cin>>s;
    s+=',';
    tmp = 0;
    len = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] != ','){
            tmp = tmp * 10 + s[i]-'0';
        }else{
            dis[++len] = tmp;
            tmp = 0;
        }
    }
    // dis[++len] = 0;
    vector<int> dp(n + 5, inf);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int cost = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (cost + dis[j] > 100) break;
            cost += dis[j];
            if (j - 1 >= 1 && hig[j] >= hig[j - 1] && hig[j] >= hig[j + 1]) {
                dp[i] = min(dp[j] + 1, dp[i]);
                break;
            }
            dp[i] = min(dp[j] + 1, dp[i]);
        }
        cout << i << " " << dp[i] << endl;
    }
    cout << dp[n] - 1 << endl;
}


int main(){

    solve();

    return 0;
}

/*
9
20,60,20,30,30,40,50,10,20
30,30,30,30,30,30,30,30

9
20 60 20 30 30 40 50 10 20
30 30 30 30 30 30 30 30

5
60 20 20 60 10
10 10 10 10

*/