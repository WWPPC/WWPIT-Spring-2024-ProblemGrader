#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int nums[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> nums[i];
    if(n&1) k = min(k,1);
    else k&=1;
    if(k){
        int x = 0;
        for(int i = 0; i<n; i++) x^=nums[i];
        for(int i = 0; i<n; i++)
            cout << (nums[i]^x) << " ";
    }else for(int i = 0; i<n; i++) cout << nums[i] << " ";
    cout << "\n";
}