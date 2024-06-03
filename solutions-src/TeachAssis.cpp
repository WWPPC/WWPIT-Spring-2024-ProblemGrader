#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5;
vector<pair<int,int>> g[MAXN];
bool need[MAXN];
void dfs1(int s, int p){
    for(auto& a: g[s]) if(a.first != p){
        dfs1(a.first,s);
        if(need[a.first]) need[s] = 1;
    }
}
ll dfs2(int s, int p){
    ll ans = 0;
    for(auto& a: g[s]) if(a.first != p && need[a.first])
        ans+=dfs2(a.first,s)+a.second;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for(int i = 1; i<n; i++){
        int a, b, w; cin >> a >> b >> w;
        g[--a].push_back({--b,w});
        g[b].push_back({a,w});
    }
    while(k--){
        int x; cin >> x;
        need[x-1] = 1;
    }
    dfs1(0,-1);
    cout << (dfs2(0,-1)<<1) << "\n";
}