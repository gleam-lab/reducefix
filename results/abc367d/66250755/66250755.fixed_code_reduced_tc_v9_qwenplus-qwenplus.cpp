#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> prefix_sums(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        a %= m;
        prefix_sums[i] = (prefix_sums[i - 1] + a) % m;
        if (i > 0) prefix_sums[i + n] = (prefix_sums[i + n - 1] + a) % m;
    }

    // Coordinate compression
    set<long long> unique_vals;
    for (int i = 0; i <= 2 * n; ++i) {
        unique_vals.insert(prefix_sums[i]);
    }

    map<long long, int> compress;
    int idx = 0;
    for (auto val : unique_vals) {
        compress[val] = idx++;
    }

    vector<int> fenwick_tree(idx + 2, 0);

    auto update = [&](int pos, int delta) {
        while (pos < fenwick_tree.size()) {
            fenwick_tree[pos] += delta;
            pos += pos & -pos;
        }
    };

    auto query = [&](int pos) {
        int res = 0;
        while (pos > 0) {
            res += fenwick_tree[pos];
            pos -= pos & -pos;
        }
        return res;
    };

    long long result = 0;

    // We count in the following way:
    // For each i from n to 2n-1, we want to find number of j < i where
    // prefix_sum[j] == prefix_sum[i]
    // Because this implies sum[j+1..i] mod m == 0
    for (int i = n; i <= 2 * n - 1; ++i) {
        // Before querying, remove prefix_sums[i-n] from the structure
        if (i > n) {
            update(compress[prefix_sums[i - n]] + 1, -1);
        }
        // Count how many times current prefix sum has occurred before
        result += query(compress[prefix_sums[i]] + 1) - query(compress[prefix_sums[i]]);
        // Add current prefix sum to the structure
        update(compress[prefix_sums[i]] + 1, 1);
    }

    cout << result << endl;
    return 0;
}