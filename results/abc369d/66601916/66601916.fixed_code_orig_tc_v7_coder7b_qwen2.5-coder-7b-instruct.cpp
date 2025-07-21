#include <iostream>
#include <climits>
#include <vector>

using namespace std;

long long solve(int n, vector<int>& nums) {
    if (n == 0) return 0;
    long long dp0 = 0, dp1 = INT_MIN;
    for (int x : nums) {
        dp0 = max(dp1 + 2LL * x, dp0);
        dp1 = max(dp0 - x, dp1);
    }
    return max(dp0, dp1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) cin >> num;
    cout << solve(n, nums) << endl;
    return 0;
}