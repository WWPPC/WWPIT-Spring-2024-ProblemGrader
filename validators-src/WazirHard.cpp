#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); //Fast input/output, not necessary for this problem
	int numTests; cin >> numTests;
    vector<ll> answer(numTests);
	for (int test = 0; test < numTests; test++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll oldDeltaX = abs(x2-x1);
		ll oldDeltaY = abs(y2-y1);
		ll diff = abs(oldDeltaY-oldDeltaX);
		if (oldDeltaY > oldDeltaX) swap(oldDeltaX, oldDeltaY);
	    if (oldDeltaX >= oldDeltaY * 2) {
            answer[test] = (oldDeltaX+1)/2;
	    }
	    else {
	        oldDeltaX -= diff * 2;
	        answer[test] = (2 * oldDeltaX + 2) / 3 + diff;
	    }
	}
    for(ll& i: answer){
        ll k; cin >> k;
        if(k != i){
            cout << "0";
            return 0;
        }
    }
    cout << "1";
}