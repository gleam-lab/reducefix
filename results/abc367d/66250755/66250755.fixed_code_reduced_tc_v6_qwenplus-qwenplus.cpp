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
        prefix_sums[i + n] = (prefix_sums[i + n - 1] + a) % m;
    }

    map<int, int> count;
    long long result = 0;

    // We need to count how many times each prefix sum modulo m appears
    // in the first n positions. Then, for each prefix sum in the full array,
    // we add the count of the same value, but only if it's from the second half.
    for (int i = 0; i < n; ++i) {
        count[prefix_sums[i]]++;
    }

    for (int i = n; i <= 2 * n; ++i) {
        result += count[prefix_sums[i]];
    }

    cout << result << endl;
    return 0;
}