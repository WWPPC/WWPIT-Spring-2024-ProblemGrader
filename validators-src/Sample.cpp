#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int submission_ans; cin >> submission_ans;
    cout << (submission_ans == accumulate(nums.begin(), nums.end(), 0) ? 1 : 0);
}