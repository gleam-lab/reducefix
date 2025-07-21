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
        prefixSum[i + 1] = (prefixSum[i] + nums[i]) % m; // Take mod here to reduce size and help with wrapping
    }

    // We'll count occurrences of each remainder
    vector<int> remainderCount(m, 0);

    // Count how many times each remainder appears in prefix sums
    for (int i = 0; i <= n; i++) {
        remainderCount[prefixSum[i]]++;
    }

    long long totalCount = 0;

    // For each remainder, use combination formula C(n, 2) = n * (n - 1) / 2
    for (int i = 0; i < m; i++) {
        long long count = remainderCount[i];
        totalCount += count * (count - 1) / 2;
    }

    cout << totalCount << endl;
    return 0;
}