#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5, LOG = 31;
int dsu[MAXN], up[MAXN];
int basis[MAXN][LOG];
void insert(int num, int node){
    for(int i = LOG-1; i>=0; i--){
        if(!((num>>i)&1)) continue;
        if(!basis[node][i]){
            basis[node][i] = num;
            return;
        }
        num^=basis[node][i];
    }
}
int get(int s){
    if(dsu[s] < 0) return s;
    int top = get(dsu[s]);
    up[s]^=up[dsu[s]];
    return dsu[s] = top;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i<MAXN; i++) dsu[i] = -1;
    int N, Q; cin >> N >> Q; while(Q--){
        int t; cin >> t; if(t == 1){
            int a, b, w; cin >> a >> b >> w;
            int x = get(--a), y = get(--b);
            if(x == y) insert(up[a]^up[b]^w, x);
            else{
                if(dsu[x] > dsu[y]){
                    swap(x, y);
                    swap(a, b);
                }
                for(int i = 0; i<LOG; i++)
                    if(basis[y][i]) insert(basis[y][i], x);
                up[y] = up[b]^w^up[a];
                dsu[x]+=dsu[y];
                dsu[y] = x;
            }
        }else{
            int a, b; cin >> a >> b;
            if(get(--a) != get(--b)) cout << "-1\n";
            else{
                int ans = up[a]^up[b], node = get(a);
                for(int i = LOG-1; i>=0; i--)
                    if((ans>>i)&1) ans^=basis[node][i];
                cout << ans << "\n";
            }
        }
    }
}