#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3;
int cost[MAXN*MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    int p = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x; cin >> x;
            if(x) cost[p++] = min(i,n-i-1)+min(j,m-j-1)+x;
        }
    }
    if(p <= k){
        cout << "0\n";
        return 0;
    }
    sort(cost,cost+p);
    long long ans = 0;
    for(int i = 0; i<p-k; i++) ans+=cost[i];
    cout << ans << "\n";
}