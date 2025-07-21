#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    // Compute modulo for all possible circular segments
    long long total_sum = prefix_sum[n];
    unordered_map<long long, int> mod_count;
    mod_count[0] = 1; // To account for prefix sums that are 0 mod m

    long long count = 0;
    for (int i = 1; i <= n; i++) {
        long long mod = (prefix_sum[i] % m + m) % m;
        count += mod_count[mod];
        mod_count[mod]++;
    }

    // Now handle circular cases (s > t)
    // The circular segment sum is total_sum - (prefix_sum[t] - prefix_sum[s])
    // Which is equivalent to total_sum - (prefix_sum[t] - prefix_sum[s])
    // We need this to be ≡ 0 mod m
    // So prefix_sum[t] - prefix_sum[s] ≡ total_sum mod m
    // Which means prefix_sum[s] ≡ prefix_sum[t] - total_sum mod m

    // We can reuse the same prefix sums but with adjusted mod values
    unordered_map<long long, int> mod_count_circular;
    long long circular_count = 0;
    long long total_mod = total_sum % m;

    for (int i = 1; i <= n; i++) {
        long long desired_mod = (prefix_sum[i] - total_mod) % m;
        desired_mod = (desired_mod + m) % m; // Ensure positive
        circular_count += mod_count_circular[desired_mod];
        mod_count_circular[(prefix_sum[i] % m + m) % m]++;
    }

    cout << count + circular_count << endl;
    return 0;
}