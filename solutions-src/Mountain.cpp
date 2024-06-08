#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while(t--){
        ll n, k; cin >> n >> k;
        ll lo = 1, hi = n;
        while(lo<hi){
            ll m = (lo+hi)>>1;
            ll r = (n-1)/m+1;
            if(n*r-m*(r*(r-1)/2) <= k) hi = m;
            else lo = m+1;
        }
        cout << lo-1 << "\n";
    }
}
