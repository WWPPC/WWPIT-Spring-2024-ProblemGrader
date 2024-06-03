#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int mod = 1e9+7;
    vector<int> answer;
	int t; cin >> t; while(t--){
		ll n; cin >> n;
		ll ans; ll c = (n/6+1)%mod;
		ll sq = c*c%mod;
		ll cb = sq*c%mod;
		switch(n%6){
		case 1:
			ans = (((60*cb%mod-111*sq%mod+mod)%mod+63*c%mod)%mod+mod-10)%mod;
			break;
		case 3:
			ans = ((60*cb%mod-51*sq%mod+mod)%mod+9*c%mod)%mod;
			break;
		case 5:
			ans = ((60*cb%mod+9*sq%mod)%mod-5*c%mod+mod)%mod;
			break;
		}
		answer.push_back(ans*500000004%mod);
	}
    for(int& i: answer){
        int k; cin >> k;
        if(k != i){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}