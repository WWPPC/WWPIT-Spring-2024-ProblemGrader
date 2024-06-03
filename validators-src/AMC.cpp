#include <bits/stdc++.h>
using namespace std;
const int MAXM = 22;
int cnt[MAXM][MAXM];
int dp[1<<MAXM];
bool did[MAXM];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int j = 0; j < n; j++){
        for(int i = 0; i<m; i++){
            int x; cin >> x;
            cnt[i][x-1]++;
        }
    }
    for(int i = 1; !(i>>m); i++){
        dp[i] = INT_MAX;
        int k = m-__builtin_popcount(i);
        for(int j = 0; j<m; j++) if((i>>j)&1)
            dp[i] = min(dp[i],dp[i^(1<<j)]+cnt[k][j]);
    }
    int ans = dp[(1<<m)-1];
    int a; cin >> a;
    if(a != ans){
        cout << "0";
        return 0;
    }
    int c = 0;
    for(int i = 0; i<m; i++){
        int k; cin >> k;
        if(k<1 || k>m || did[k-1]){
            cout << "0";
            return 0;
        }
        did[k-1] = 1;
        c+=cnt[i][k-1];
    }
    cout << (c==a?"1":"0");
}