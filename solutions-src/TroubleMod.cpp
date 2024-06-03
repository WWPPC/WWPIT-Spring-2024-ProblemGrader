#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 5e4, mod = 1e9+7;
map<int,int> maxLcm[MAX+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; while(n--){
        int x; cin >> x;
        vector<pair<int,int>> cnt;
        int c = x;
        for(int i = 2; i*i<=x; i++) if(c%i == 0){
            cnt.push_back({i,0});
            while(c%i == 0){
                c/=i;
                cnt[cnt.size()-1].second++;
            }
        }
        if(c-1) cnt.push_back({c,1});
        for(int i = 1; i*i<=x; i++) if(x%i == 0)
            for(auto& a: cnt){
                maxLcm[i][a.first] = max(maxLcm[i][a.first],a.second);
                maxLcm[x/i][a.first] = max(maxLcm[x/i][a.first],a.second);
            }
    }
    long double best = 0;
    ll ans = 0;
    for(int i = 1; i<=MAX; i++) if(maxLcm[i].size()){
        long double curr = logl(i);
        ll val = 1;
        for(auto& a: maxLcm[i]){
            curr+=a.second*log(a.first);
            while(a.second--> 0) val = val*a.first%mod;
        }
        if(curr > best){
            best = curr;
            ans = val*i%mod;
        }
    }
    cout << ans << "\n";
}