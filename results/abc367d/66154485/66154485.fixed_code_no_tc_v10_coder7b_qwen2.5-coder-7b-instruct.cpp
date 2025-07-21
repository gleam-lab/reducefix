#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate prefix sums modulo m to efficiently check for subarray sums divisible by m
    vector<int> prefixSumModM(m);
    prefixSumModM[arr[0] % m]++;
    
    for (int i = 1; i < n; i++) {
        arr[i] = (arr[i] + arr[i - 1]) % m;
        prefixSumModM[arr[i]]++;
    }

    // Count subarrays that have a sum divisible by m
    for (int i = 0; i < m; i++) {
        // Each pair of indices with the same prefix sum modulo m forms a valid subarray
        ans += prefixSumModM[i] * (prefixSumModM[i] - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}