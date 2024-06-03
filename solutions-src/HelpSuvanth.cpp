#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
const ll mx = 1e18;
vector<ll> f,dp;
ll solve(ll c){
    int cnt = 0;
    ll ans = 0;
    for(int i = f.size()-1; i>=0; i--) if(c >= f[i]){
        c-=f[i];
        ans = (ans+dp[i]+cnt*f[i]%mod)%mod;
        cnt++;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i<2; i++){
        dp.push_back(1);
        f.push_back(1);
    }
    while(f[f.size()-1]<mx){
        dp.push_back((dp[dp.size()-1]+dp[dp.size()-2]+f[f.size()-2]-1)%mod);
        f.push_back(f[f.size()-1]+f[f.size()-2]);
    }
    int t; cin >> t; while(t--){
        ll l, r; cin >> l >> r;
        cout << (solve(r)-solve(l-1)+mod)%mod << "\n";
    }
}