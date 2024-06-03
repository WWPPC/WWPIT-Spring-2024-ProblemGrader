#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> pos(n,vector<int>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x; cin >> x;
            pos[x-1][j] = i;
        }
    }
    for(auto& a: pos){
        int ans = 0;
        for(int i = 1; i<m; i++) ans+=abs(a[i]-a[i-1]);
        cout << ans << "\n";
    }
}