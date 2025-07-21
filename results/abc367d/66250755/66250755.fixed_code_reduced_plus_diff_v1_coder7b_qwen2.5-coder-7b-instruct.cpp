#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    vector<long long> a(n), prefix_sum(n * 2);
    unordered_map<int, long long> count;

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % m;
    }

    for (long long i = n; i < 2 * n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i - n]) % m;
    }

    long long ans = 0;
    for (long long i = n; i <= 2 * n; ++i) {
        ans += count[(prefix_sum[i] - prefix_sum[i - n] + m) % m];
        count[prefix_sum[i]]++;
    }

    cout << ans << '\n';

    return 0;
}