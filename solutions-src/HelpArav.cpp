#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while(t--){
        int n; cin >> n;
        ll m1 = 0, m2 = 0;
        while(n--){
            ll x; cin >> x;
            if(x > m1){
                m2 = m1;
                m1 = x;
            }else if(x > m2) m2 = x;
        }
        cout << m1*m2 << "\n";
    }
}