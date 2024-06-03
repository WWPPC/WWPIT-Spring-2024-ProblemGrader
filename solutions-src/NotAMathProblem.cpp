#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MAXN = 2e5;
Tree<int> v[MAXN+1];
int nums[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for(int i = 0; i<n; i++){
        cin >> nums[i];
        v[nums[i]].insert(i);
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, k; cin >> l >> k; l--;
            v[nums[l]].erase(l);
            v[nums[l] = k].insert(l);
        }else{
            int l, r, k, ans = 0; cin >> l >> r >> k; l--;
            for(int i = k; i<=MAXN; i+=k)
                ans+=v[i].order_of_key(r)-v[i].order_of_key(l);
            cout << ans << "\n";
        }
    }
}