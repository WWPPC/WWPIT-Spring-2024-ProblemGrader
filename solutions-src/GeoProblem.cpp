#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while(t--){
        ll n, k; cin >> n >> k;
        if(n < 3) cout << k << "\n";
        else{
            ll c = (n+3)>>1;
            cout << (k*n+c-1)/c << "\n";
        }
    }
}