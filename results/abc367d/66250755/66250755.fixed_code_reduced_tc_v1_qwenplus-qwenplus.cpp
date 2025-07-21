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

    map<long long, int> count;
    long long result = 0;

    // We will consider all subarrays of length at most n
    for (int i = 0; i < 2 * n; ++i) {
        if (i >= n) count[prefix_sums[i - n]]--;
        result += count[prefix_sums[i]];
        count[prefix_sums[i]]++;
    }

    cout << result << endl;
    return 0;
}