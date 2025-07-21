#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Compute prefix sums modulo m
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = (prefixSum[i] + nums[i]) % m;
    }

    // Use a map to count occurrences of each remainder
    map<int, int> remainderCount;
    long long count = 0;

    for (int i = 0; i <= n; i++) {
        // For each prefix sum, find how many previous prefixes have the same remainder
        // because (prefixSum[j] - prefixSum[i]) % m == 0 iff prefixSum[j] % m == prefixSum[i] % m
        int rem = prefixSum[i] % m;
        count += remainderCount[rem];
        remainderCount[rem]++;
    }

    cout << count << endl;
    return 0;
}