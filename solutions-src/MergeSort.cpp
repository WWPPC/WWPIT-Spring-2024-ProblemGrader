#include <bits/stdc++.h>
using namespace std;

#define p pair
#define v vector

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	v<p<int, int>> one(n);
	v<p<int, int>> two(n);
	for (int i = 0; i < n; i++) {
		cin>> one[i].second >> one[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> two[i].second >> two[i].first;
	}

	if (one.back().first > two.back().first) swap(one, two);
	//now two is the one with extra elmnts
	auto it = lower_bound(two.begin(), two.end(), make_pair(one.back().first, 0));
	long long ctr = 0;
	for (auto jt = it; jt < two.end(); jt++) {
		ctr -= jt->second;
	}
	for (p<int, int> pi : one) {
		ctr += pi.second;
	}
	for (p<int, int> pi : two) {
		ctr += pi.second;
	}

	cout << ctr;
}