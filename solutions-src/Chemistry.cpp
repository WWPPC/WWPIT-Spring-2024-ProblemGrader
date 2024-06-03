#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int edges[MAXN][3];
vector<int> g[MAXN];
int tin[MAXN], low[MAXN];
bool vis[MAXN];
int n, m, timer;
bool dfs(int s, int p) {
    vis[s] = 1;
    tin[s] = low[s] = timer++;
    for (int i : g[s]) if(i != p){
        if(vis[i]) low[s] = min(low[s],tin[i]);
        else{
            if(!dfs(i,s)) return 0;
            low[s] = min(low[s],low[i]);
            if(low[i] > tin[s]) return 0;
        }
    }
    return 1;
}
bool works(int t){
    timer = 0;
    for(int i = 0; i<n; i++){
        tin[i] = low[i] = -1;
        vis[i] = 0;
        g[i].clear();
    }
    for(int i = 0; i<m; i++) if(edges[i][2]>=t){
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }
    if(!dfs(0,-1)) return 0;
    for(int i = 0; i<n; i++) if(!vis[i]) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i<m; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2], --edges[i][0], --edges[i][1];
    int lo = 0, hi = 1e9;
    while(lo<hi){
        int m = (lo+hi+1)>>1;
        if(works(m)) lo = m;
        else hi = m-1;
    }
    cout << lo << "\n";
}