#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define v vector

#define dis distance
#define all(iterable) iterable.begin(), iterable.end()

const ll mod = 1e9+7;

ll ans(ll a, v<ll>& f, v<ll>& sum) {
	ll res = 0;
	while (a > 0) {
		int i = dis(f.begin(), --upper_bound(all(f), a));
		a -= f[i];
		res += sum[i] + a;
		res %= mod;
	}
	assert(a==0 && "zeckendorf bork");
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	v<ll> f(89);
	f[0]=0; f[1]=1;
	for (int i = 2; i < 89; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	v<ll> sum(89, -1);
	sum[1]=sum[2]=1;
	for (int i = 3; i < 89; i++) {
		sum[i] = sum[i-1] + sum[i-2] + f[i-2] - 1;
		sum[i] %= mod;
	}
	
	int t; cin >> t;
    vector<int> answer(t);
	for(int i = 0; i<t; i++){
		ll l, r; cin >> l >> r;
		answer[i] = (ans(r,f,sum)-ans(l-1,f,sum)+mod)%mod;
	}
    for(int& i: answer){
        int k; cin >> k;
        if(i != k){
            cout << "0";
            return 0;
        }
    }
    cout << "1";
}