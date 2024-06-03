#include <bits/stdc++.h>
using namespace std;
const int MAXM = 22;
int cnt[MAXM][MAXM];
int dp[1<<MAXM];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while(n-->0){
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
    cout << dp[(1<<m)-1] << "\n";
    for(int x = (1<<m)-1, k = 0; x; k++)
        for(int i = 0; i<m; i++)
            if(((x>>i)&1) && dp[x^(1<<i)]+cnt[k][i]==dp[x]){
                cout << i+1 << " ";
                x^=1<<i;
                break;
            } cout << "\n";
}