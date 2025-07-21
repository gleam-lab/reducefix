#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
long long a[2 * N], prefix_sum[2 * N];
map<long long, long long> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    long long res = 0;
    cnt[0] = 1;
    for (int i = 1; i < 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i]) % m;
        res += cnt[prefix_sum[i]];
        if (i < n) {
            cnt[prefix_sum[i]]++;
        }
    }

    cout << res << endl;
    return 0;
}