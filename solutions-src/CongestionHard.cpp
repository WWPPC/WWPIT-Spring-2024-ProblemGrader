#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> down;
vector<int> depth;
int dfs(int s, int p){
    depth[s] = depth[p]+1;
    down.push_back(s);
    int a = depth[s];
    for(int i: g[s]) if(i != p)
        a = max(a,dfs(i,s));
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    g.resize(n);
    for(int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    depth.resize(n);
    depth[0] = -1;
    vector<set<int>> can;
    vector<int> top(n);
    int p = 0;
    for(int s: g[0]){
        can.push_back(set<int>());
        int mx = dfs(s,0);
        for(int i: down) top[i] = p;
        down.clear();
        for(int i = 0; i<=mx; i++)
            can[p].insert(i);
        p++;
    }
    cout << "0 ";
    int ret = 0;
    vector<int> ans(p), md(p);
    for(int i = 1; i<n; i++){
        int t = top[i];
        int d = depth[i];
        auto it = can[t].lower_bound(d);
        if(it == can[t].end())
            ans[t]++;
        else{
            can[t].erase(*it);
            md[t] = max(md[t],*it);
        }
        ret = max(ret,ans[t]+md[t]);
        cout << ret+1 << " ";
    }
    cout << "\n";
}