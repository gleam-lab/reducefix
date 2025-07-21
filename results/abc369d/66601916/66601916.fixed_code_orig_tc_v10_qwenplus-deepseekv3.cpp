#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << max(0LL, nums[0]) << endl;
        return 0;
    }

    long long prev_prev = 0;               // dp[i-2]
    long long prev = max(0LL, nums[0]);    // dp[i-1]
    
    for (int i = 2; i <= n; i++) {
        long long current = max(prev, prev_prev + nums[i-1]);
        prev_prev = prev;
        prev = current;
    }

    cout << prev << endl;
    return 0;
}