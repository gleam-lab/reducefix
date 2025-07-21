#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = (prefixSum[i] + nums[i]) % m;  // Maintain mod m to prevent overflow and help with calculation
    }

    // We will count the number of pairs (i, j) such that prefixSum[j] == prefixSum[i] (mod m)
    // Because (prefixSum[j] - prefixSum[i]) % m == 0 means the subarray sum is divisible by m

    unordered_map<int, int> countMap;
    int result = 0;

    for (int i = 0; i <= n; i++) {
        // Count how many times this mod value has occurred before
        result += countMap[prefixSum[i]]++;
    }

    cout << result << endl;
    return 0;
}