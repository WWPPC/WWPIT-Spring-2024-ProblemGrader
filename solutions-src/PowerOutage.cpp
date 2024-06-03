#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
long long dp[MAXN];
vector<pair<int,int>> inter[MAXN];
int main(){
    int n, m; cin >> n >> m;
    while(m--){
        int l, r, w; cin >> l >> r >> w;
        inter[r-1].push_back({l-1,w});
    }
    for(int i = 0; i<n; i++){
        dp[i] = LLONG_MAX>>1;
        for(auto& a: inter[i])
            dp[i] = min(dp[i], (a.first?dp[a.first-1]:0)+a.second);
    }
    cout << (dp[n-1] == LLONG_MAX>>1 ? -1:dp[n-1]) << "\n";
}