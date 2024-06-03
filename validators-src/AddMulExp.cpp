#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; 
    vector<ll> answer(t);
    for (int i = 0; i < t; i++){
        ll n, x; int m; cin >> n >> x >> m;
        x%=m;
        ll ans = 0, pow = 1;
        ll curr = 0, sum = 1;
        for(int i = 63; i>=0; i--){
            if((n>>i)&1){
                curr++;
                pow = pow*x%m;
                sum = (sum+pow)%m;
                ans = (ans+curr*pow%m)%m;
            }
            if(n>>i && i){
                ll p = sum;
                sum = (sum-1)*(pow+1)%m+1;
                ans = (((ans-curr*pow%m+m)%m)*(pow*x%m+1)%m+curr*pow%m+
                    ((sum-p+m)%m)*(curr+1)%m)%m;
                pow = pow*pow%m;
                curr = (curr<<1)%m;
            }
        }
        answer[i] = ans;
    }
    for(ll i: answer){
        ll k; cin >> k;
        if(k != i){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}