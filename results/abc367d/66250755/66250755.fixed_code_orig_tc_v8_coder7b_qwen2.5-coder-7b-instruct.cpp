#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2 * 100005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), prefix_sum(2 * n + 1, 0), count(m, 0);
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[n + i] = a[i];
    }

    for (int i = 1; i <= 2 * n; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + a[i - 1]) % m;
        if (i > n) {
            ans += count[prefix_sum[i - n]];
        }
        count[prefix_sum[i]]++;
    }

    cout << ans << endl;
    return 0;
}