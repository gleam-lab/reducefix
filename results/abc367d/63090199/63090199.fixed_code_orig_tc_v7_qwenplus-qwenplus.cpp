#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Use a map to count how many times each remainder occurs in prefix sums mod m
    unordered_map<int, int> remainder_count;
    long long prefix_sum = 0;
    long long result = 0;

    // Initially, remainder 0 has been seen once (empty prefix)
    remainder_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum += nums[i];
        int rem = (prefix_sum % m + m) % m;  // Ensure non-negative

        // Count how many times this remainder was seen before
        result += remainder_count[rem];

        // Update the count for this remainder
        remainder_count[rem]++;
    }

    cout << result << endl;
    return 0;
}