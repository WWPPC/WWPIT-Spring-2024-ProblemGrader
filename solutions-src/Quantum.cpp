#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
ll inv(ll x){
    ll a = 1;
    int k = mod-2;
    while(k){
        if(k&1) a = a*x%mod;
        x = x*x%mod;
        k>>=1;
    }
    return a;
}
const int MAXN = 100;
ll mat[MAXN][MAXN];
ll mat2[MAXN][MAXN];
ll ans[MAXN][MAXN];
ll vec[MAXN];
ll ret[MAXN];
int n;
vector<int> g[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, e; ll t; cin >> n >> m >> e >> t;
    while(m--){
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    for(int i = 0; i<n; i++){
        ll d = inv(g[i].size());
        for(int j: g[i]) mat[i][j] = d;
    }
    for(int i = 0; i<n; i++) ans[i][i] = 1;
    while(t){
        if(t&1){
            for(int i = 0; i<n; i++)
                for(int j = 0; j<n; j++){
                    mat2[i][j] = 0;
                    for(int k = 0; k<n; k++)
                        mat2[i][j] = (mat2[i][j]+mat[i][k]*ans[k][j]%mod)%mod;
                }
            for(int i = 0; i<n; i++)
                for(int j = 0; j<n; j++)
                    ans[i][j] = mat2[i][j];
        }
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++){
                mat2[i][j] = 0;
                for(int k = 0; k<n; k++)
                    mat2[i][j] = (mat2[i][j]+mat[i][k]*mat[k][j]%mod)%mod;
            }
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                mat[i][j] = mat2[i][j];
        t>>=1;
    }
    while(e--){int c; cin >> c; vec[c-1]++;}
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            ret[j] = (ret[j]+vec[i]*ans[i][j]%mod)%mod;
    for(int i = 0; i<n; i++)
        cout << ret[i] << " ";
    cout << "\n";
}