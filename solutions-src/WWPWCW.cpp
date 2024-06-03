#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& i: a) cin >> i;
    for(int& i: b) cin >> i;
    while(1){
        bool changed = 0;
        for(int i = 0; i<n-1; i++){
            int c = a[i+1]+b[i];
            if(c<a[i]){
                a[i] = c;
                changed = 1;
            }
        }
        for(int i = 0; i<n-1; i++){
            int c = a[i]<<1;
            if(c<a[i+1]){
                a[i+1] = c;
                changed = 1;
            }
        }
        for(int i = 0; i<n-1; i++){
            int c = b[i]<<1;
            if(c<b[i+1]){
                b[i+1] = c;
                changed = 1;
            }
        }
        if(!changed) break;
    }
    for(int i = 0; i<n; i++) cout << a[i] << " "; cout << "\n";
}