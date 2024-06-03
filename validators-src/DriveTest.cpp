#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
using ll = long long;
ll r[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, d; cin >> n >> a >> d;
    for(int i = 0; i<n; i++)
        cin >> r[i];
    for(int i = n-2; i>=0; i--)
        r[i] = min(r[i], r[i+1]+d);
    ll speed = 0;
    long double ans = 0;
    for(int i = 0; i<n; i++){
        speed = min(speed+a,r[i]);
        ans+=((long double)1)/speed;
    }
    long double x; cin >> x;
    if(abs(x-ans) > 1e-4) cout << 0;
    else cout << 1;
}