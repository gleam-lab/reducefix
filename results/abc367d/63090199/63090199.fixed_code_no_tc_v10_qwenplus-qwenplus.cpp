#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Compute prefix sums modulo m
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_mod[i] = (prefix_mod[i - 1] + nums[i - 1]) % m;
    }

    // Count frequency of each remainder
    unordered_map<int, int> mod_count;
    mod_count[0] = 1; // Important for subarrays starting from index 0

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        // For current prefix mod value, count how many times it has occurred before
        result += mod_count[prefix_mod[i]];
        mod_count[prefix_mod[i]]++;
    }

    cout << result << endl;
    return 0;
}