#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define arr array<int, 3>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        // Sort pairs based on the ratio of A_i / B_i in descending order
        for (int i = 1; i <= n; i++) {
            sa[i] = {a[i], b[i]};
        }
        sort(sa + 1, sa + 1 + n, [&](const PII &p1, const PII &p2) {
            return (double)p1.fi / p1.se > (double)p2.fi / p2.se;
        });

        vector<int> max_a(k, -1);
        vector<int> sum_b(k, 0);

        for (int i = 0; i < k; i++) {
            max_a[i] = sa[i + 1].fi;
            sum_b[i] = sa[i + 1].se;
        }

        int res = max_a[0] * sum_b[0];

        for (int i = k; i < n; i++) {
            int new_max = sa[i + 1].fi;
            int new_sum = sa[i + 1].se;

            // Find the index where new_max should replace old_max
            int j = 0;
            while (j < k && max_a[j] >= new_max) {
                j++;
            }

            if (j == k) continue; // If no replacement needed, skip

            // Update the result with the potential new minimum
            res = min(res, new_max * (sum_b[0] - sum_b[j]) + max_a[0] * sum_b[j]);
        }

        cout << res << endl;
    }

    return 0;
}