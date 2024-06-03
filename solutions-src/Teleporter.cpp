#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define p pair
#define v vector
#define dq deque
#define q queue
#define pq priority_queue
#define uset unordered_set
#define umap unordered_map
#define arr array
#define mset multiset

#define dis distance
#define all(iterable) iterable.begin(), iterable.end()
#define fir first
#define sec second

#define sp " "
#define spsp "  "
#define nl "\n"
#define nlnl "\n\n"

const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> n >> m;
	v<p<int,int>> nums(m);
	for (int i = 0; i < m; i++) {
		int a,b;cin >> a >> b;
		nums[i]={a+b,i};
	}
	sort(all(nums));
	int orig=-nums[m-1].fir+nums[0].fir+n+n; //avoid int overflow oops
	int close = dis(nums.begin(), upper_bound(all(nums), make_pair(nums[0].fir, INT_MAX)));
	int far = dis(lower_bound(all(nums), make_pair(nums[m-1].fir, -1)), nums.end());
	if (close+far>m) {
		//closest teleporter is also a farthest teleporter oof
		cout << 2*n << nl;
		return 0;
	}
	int dist1 = nums[0].fir-2;
	int dist2 = -nums[m-1].fir+n+n;
	bool wait=1;
	if (dist1%m!=0) {
		int g = gcd(dist1, m);
		if (g==1) {
			wait=0;
		} else {
			//store whether a has a residue here
			v<bool> residue(g,0);
			for (int i = 0; i < close; i++) {
				residue[nums[i].sec%g]=true;
			}
			for (int i = 0; i < far; i++) {
				if (residue[nums[m-i-1].sec%g]) {
					wait=0;
					break;
				}
			}
		}
	}

	cout << dist1+dist2+wait << nl;
}