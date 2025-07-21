#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // To count prefix_sum mod m occurrences
    map<int, long long> mod_count;
    long long count = 0;
    long long prefix_sum = 0;

    // Initially, there is one prefix sum with mod 0 (sum = 0 before array starts)
    mod_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum += nums[i];
        int mod = ((prefix_sum % m) + m) % m; // Ensure non-negative

        // Every time we've seen this mod before, those are valid previous indices
        count += mod_count[mod];

        // Count current mod value
        mod_count[mod]++;
    }

    cout << count << endl;
    return 0;
}