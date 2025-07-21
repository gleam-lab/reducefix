#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate prefix sums modulo m
    vector<int> prefixSumModM(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSumModM[i] = (prefixSumModM[i - 1] + arr[i - 1]) % m;
    }

    unordered_map<int, int> countMap;
    countMap[0]++; // Base case for subarray starting from index 0

    for (int i = 1; i <= n; i++) {
        // Count how many times the same remainder has appeared before
        ans += countMap[prefixSumModM[i]];
        countMap[prefixSumModM[i]]++;
    }

    cout << ans << endl;
    return 0;
}