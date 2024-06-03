#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int dis1[MAXN],dis2[MAXN];
int p[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        cin >> p[i];
        dis1[i] = dis2[i] = INT_MAX;
    }
    int a, b; cin >> a >> b;
    dis1[--a] = dis2[--b] = 0;
    queue<int> bfs;
    bfs.push(a);
    while(bfs.size()){
        int c = bfs.front(); bfs.pop();
        if(p[c]+c<n && dis1[p[c]+c] == INT_MAX){
            dis1[p[c]+c] = dis1[c]+1;
            bfs.push(p[c]+c);
        }
        if(c-p[c]>=0 && dis1[c-p[c]] == INT_MAX){
            dis1[c-p[c]] = dis1[c]+1;
            bfs.push(c-p[c]);
        }
    }
    bfs.push(b);
    while(bfs.size()){
        int c = bfs.front(); bfs.pop();
        if(p[c]+c<n && dis2[p[c]+c] == INT_MAX){
            dis2[p[c]+c] = dis2[c]+1;
            bfs.push(p[c]+c);
        }
        if(c-p[c]>=0 && dis2[c-p[c]] == INT_MAX){
            dis2[c-p[c]] = dis2[c]+1;
            bfs.push(c-p[c]);
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i<n; i++) ans = min(ans,max(dis1[i],dis2[i]));
    cout << (ans==INT_MAX?-1:ans) << "\n";
}