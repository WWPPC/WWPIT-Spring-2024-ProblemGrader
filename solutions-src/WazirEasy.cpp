#include <iostream>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); //Fast input/output, not necessary for this problem

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int deltaX = abs(x2-x1);
	int deltaY = abs(y2-y1);

	int turns;
	for (int i = 1; i < 1000000000; i++) {
		//wazir move
		if (deltaX > deltaY) {
			deltaX--;
		} else {
			deltaY--;
		}
		if (deltaX == 0 && deltaY == 0) {
			turns = i;
			break;
		}
		
		//king move
		if (deltaX != 0) {
			deltaX--;
		}
		if (deltaY != 0) {
			deltaY--;
		}
		if (deltaX == 0 && deltaY == 0) {
			turns = i;
			break;
		}
	}

	cout << turns;
};