#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int LOG = 17;
const int maxBlocks = 320;
int nums[MAXN];
int block[maxBlocks][1<<LOG];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int blockSize = (int)sqrt(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
        block[i/blockSize][nums[i]]++;
    }
    for(int i = 0; i*blockSize<n; i++)
        for(int j = 0; j<LOG; j++)
            for(int k = 0; k<1<<LOG; k++) if(!((k>>j)&1))
                block[i][k]+=block[i][k^(1<<j)];
    while(q--){
        int l, r, k; cin >> l >> r >> k;
        int a = --l/blockSize, b = --r/blockSize;
        int ans = 0;
        int end = min(r+1,(a+1)*blockSize);
        int start = b*blockSize;
        for(int i = LOG; i--;){
            int x = ans^(1<<i);
            int cnt = 0;
            for(int j = a+1; j<b; j++)
                cnt+=block[j][x];
            for(int j = l; j<end; j++)
                if((x&nums[j]) == x) cnt++;
            if(a != b) for(int j = start; j<=r; j++)
                if((x&nums[j]) == x) cnt++;
            if(cnt >= k) ans = x;
        }
        cout << ans << "\n";
    }
}
