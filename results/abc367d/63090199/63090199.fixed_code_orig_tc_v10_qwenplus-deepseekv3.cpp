#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    long long total_sum = prefix_sum[n];
    long long count = 0;

    unordered_map<int, int> mod_count;
    mod_count[0] = 1; // To account for prefix sums starting from index 0

    for (int i = 1; i <= n; ++i) {
        int mod = (prefix_sum[i] % m + m) % m;
        count += mod_count[mod];
        mod_count[mod]++;
    }

    cout << count << endl;
    return 0;
}