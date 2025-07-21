#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    long long total_sum = prefix[n];
    long long count = 0;

    // We need to find all pairs (s, t) where s != t and (prefix[t] - prefix[s]) % m == 0 if s < t
    // or (total_sum - (prefix[s] - prefix[t])) % m == 0 if s > t
    // Which simplifies to (prefix[t] - prefix[s]) % m == 0 for all s != t

    // So, we can compute prefix mod m and count pairs with the same mod

    vector<long long> mod_counts(m, 0);
    for (int i = 0; i <= n; ++i) {
        mod_counts[(prefix[i] % m + m) % m]++;
    }

    // The number of valid pairs is the sum for each mod of mod_counts[mod] choose 2
    for (int mod = 0; mod < m; ++mod) {
        count += mod_counts[mod] * (mod_counts[mod] - 1) / 2;
    }

    // However, this counts all pairs (s, t) where s != t, but we need to exclude s == t
    // But since the original problem excludes s == t, this count is correct

    cout << count << endl;

    return 0;
}