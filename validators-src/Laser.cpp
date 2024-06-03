#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int dp[MAXN][MAXN][4];
int back[MAXN][MAXN][4];
string arr[MAXN], ret[MAXN];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
#define a first
#define b second
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
				for(int k = 0; k<4; k++){
					dp[i][j][k] = INT_MAX;
					back[i][j][k] = -1;
				}
	for(int i = 0; i<n; i++) cin >> arr[i];
	deque<pair<pair<int,int>,int>> bfs;
	bfs.push_back({{0,0},0});
	dp[0][0][0] = 0;
	while(bfs.size()){
		auto c = bfs.front(); bfs.pop_front();
		int d = c.b, h = dp[c.a.a][c.a.b][c.b];
		if(arr[c.a.a][c.a.b] == '_'){
			int x = c.a.a+dir[d][0], y = c.a.b+dir[d][1];
			if(x >= 0 && y >= 0 && x<n && y<n){
				if(dp[x][y][d]>h){
					dp[x][y][d] = h;
					back[x][y][d] = c.b;
					bfs.push_front({{x,y},d});
				}
			}
			int d1 = d^1, d2 = 3-d;
			int x1 = c.a.a+dir[d1][0], y1 = c.a.b+dir[d1][1];
			int x2 = c.a.a+dir[d2][0], y2 = c.a.b+dir[d2][1];
			if(x1 >= 0 && y1 >= 0 && x1<n && y1<n){
				if(dp[x1][y1][d1]>h+1){
					dp[x1][y1][d1] = h+1;
					back[x1][y1][d1] = c.b;
					bfs.push_back({{x1,y1},d1});
				}
			}
			if(x2 >= 0 && y2 >= 0 && x2<n && y2<n){
				if(dp[x2][y2][d2]>h+1){
					dp[x2][y2][d2] = h+1;
					back[x2][y2][d2] = c.b;
					bfs.push_back({{x2,y2},d2});
				}
			}
		}else{
			if(arr[c.a.a][c.a.b] == '\\') d^=1;
			else d = 3-d;
			int x = c.a.a+dir[d][0], y = c.a.b+dir[d][1];
			if(x >= 0 && y >= 0 && x<n && y<n){
				if(dp[x][y][d]>h){
					dp[x][y][d] = h;
					back[x][y][d] = c.b;
					bfs.push_front({{x,y},d});
				}
			}
		}
	}
    int ans = INT_MAX;
	for(int i = 0; i<4; i++) ans = min(ans, dp[n-1][n-1][i]);
    for(int i = 0; i<n; i++){
        cin >> ret[i];
        if(ret[i].size() != n){
            cout << "0";
            return 0;
        }
        for(int j = 0; j<n; j++) if(arr[i][j] != '_'){
            if(ret[i][j] != arr[i][j]){
                cout << "0";
                return 0;
            }
        }else if(ret[i][j] != '_') ans--;
    }
    if(ans){
        cout << "0";
        return 0;
    }
    int x = 0, y = 0, d = 0;
	if(ret[x][y] != '_'){
		if(ret[x][y] == '\\') d^=1;
		else if(ret[x][y] == '/') d = 3-d;
		else{
			cout << "0";
			return 0;
		}
	}
    while(x != n-1 || y != n-1){
        int xt = x+dir[d][0], yt = y+dir[d][1];
        if(min(xt,yt) == -1 || max(xt,yt) == n){
            cout << "0";
            return 0;
        }
        if(ret[xt][yt] != '_'){
            if(ret[xt][yt] == '\\') d^=1;
            else if(ret[xt][yt] == '/') d = 3-d;
            else{
                cout << "0";
                return 0;
            }
        }
        x = xt;
        y = yt;
    }
    cout << "1";
}