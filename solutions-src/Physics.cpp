#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int side(pair<int,int>& a, pair<int,int>& b, pair<int,int>& c){
    return (c.y-a.y)*(b.x-a.x)-(c.x-a.x)*(b.y-a.y);
}
const int MAXN = 150;
int tri[MAXN][MAXN][MAXN];
bool did[MAXN][MAXN][MAXN];
int line[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> p(n);
    for(auto& a: p) cin >> a.x >> a.y;
    sort(p.begin(),p.end());
    for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) if(i != j) for(int k = 0; k<n; k++) if(i != k && j != k)
        if(!did[i][j][k] && side(p[i],p[j],p[k])>0 && side(p[j],p[k],p[i])>0 && side(p[k],p[i],p[j])>0){
            for(int c = 0; c<n; c++)
                if(side(p[i],p[j],p[c])>0 && side(p[j],p[k],p[c])>0 && side(p[k],p[i],p[c])>0)
                    tri[i][j][k]++;
            did[i][j][k] = did[j][k][i] = did[k][i][j] = 1;
            tri[j][k][i] = tri[k][i][j] = tri[i][j][k];
        }
    for(int i = 0; i<n; i++) for(int j = i+1; j<n; j++){
        int lx = min(p[i].x,p[j].x);
        int rx = max(p[i].x,p[j].x);
        int ly = min(p[i].y,p[j].y);
        int ry = max(p[i].y,p[j].y);
        for(int c = 0; c<n; c++) if(i != c && j != c && side(p[i],p[j],p[c]) == 0)
            if(lx <= p[c].x && p[c].x <= rx && ly <= p[c].y && p[c].y <= ry)
                line[i][j]++;
    }
    long long ans = 0;
    for(int i = 0; i<n; i++) for(int j = i+1; j<n; j++) for(int k = i+1; k<n; k++)
        if(j != k && side(p[i],p[j],p[k])>0) for(int l = i+1; l<n; l++) if(l != j && l != k)
            if(side(p[j],p[k],p[l])>0 && side(p[k],p[l],p[i])>0 && side(p[l],p[i],p[j])>0)
                ans+=tri[i][j][l]+tri[j][k][l]+(j<l?line[j][l]:line[l][j]);
    cout << ans << "\n";
}