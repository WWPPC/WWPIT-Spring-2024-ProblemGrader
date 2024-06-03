#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1000000007;
const int MAXN = 1e6;
ll fact[MAXN+1];
ll powMod(ll a, ll b) {
    ll result = 1;
    ll base = a;
    while(b){
        if(b&1) result = result * base % MOD;
        base = base * base % MOD;
        b>>=1;
    }
    return result;
}
int main() {
    int T;
    cin >> T;
    fact[0] = 1;
    for (int i = 1; i<=MAXN; i++)
        fact[i] = fact[i-1]*i%MOD;
    while(T--){
        int N;
        cin >> N;
        ll ans = 0;
        ll l = 1;
        for (int i = 0; i <= N / 2; i++) {
            if(i)
                l = (2*i%MOD-1)* l%MOD;
            ans = (ans + ((fact[N] * powMod(fact[i * 2], MOD - 2)) % MOD * powMod(fact[N - i * 2], MOD - 2)) % MOD * l) % MOD;
        }
        if (N % 4 == 0) {
            int p = 0;
            for (int i = 1; N>>i; i++) {
                if ((N >> i)&1) {
                    p = i;
                    break;
                }
            }
            ll ans2 = powMod(2, p)-1;
            for (int i = N>>1; i >= 2; i -= 2)
                ans2 = (ans2 * (i - 1) * 2) % MOD;
            cout << (ans + ans2) % MOD << "\n";
        } else cout << ans << "\n";
    }
}
