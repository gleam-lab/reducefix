#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (long long &x : a) {
        cin >> x;
        k -= x;
    }

    sort(a.begin(), a.end());

    vector<long long> prefix_sum(n + 1);
    for (long long i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[n - i];
    }

    vector<long long> results(n);
    for (long long i = 0; i < n; ++i) {
        long long required_votes = (m - 1) * prefix_sum[i] - k;
        if (required_votes < 0) {
            results[i] = 0;
        } else {
            results[i] = required_votes;
        }
    }

    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}