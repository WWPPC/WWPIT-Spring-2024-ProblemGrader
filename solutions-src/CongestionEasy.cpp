#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
int k;
void dfs(int s, int p, int d, vector<int>& count){
    if(count.size() == d) count.push_back(0);
    if(s < k) count[d]++;
    for(int i: g[s]) if(i != p)
        dfs(i,s,d+1,count);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n >> k;
    g.resize(n,vector<int>());
    for(int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    int ans = 0;
    for(int s: g[0]){
        vector<int> count;
        dfs(s,0,0,count);
        int curr = 0;
        int a = 0;
        for(int i = 0; i<count.size(); i++){
            curr+=count[i];
            if(curr){
                curr--;
                a = max(a,i+1);
            }
        }
        ans = max(ans,curr+a);
    }
    cout << ans << "\n";
}