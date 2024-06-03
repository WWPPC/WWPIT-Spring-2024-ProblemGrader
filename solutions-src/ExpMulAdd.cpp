#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int x = 1; while(b--) x*=a;
    cout << x*c+d << "\n";
}