#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, w; cin >> n >> m >> w;
    vector<ll> dp(w+1);
    while(n--){
        int s, p; cin >> s >> p;
        for(int i = w; i>=p; i--)
            dp[i] = max(dp[i],dp[i-p]+s);
    }
    vector<int> f(m);
    for(int& i: f) cin >> i;
    sort(f.begin(),f.end());
    int s = 0;
    ll ans = 0;
    for(int i = 0; i<m; i++){
        s+=f[i];
        if(s >= w) break;
        ans = max(ans,(i+1)*dp[w-s]);
    }
    cout << ans << "\n";
}