#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define arr array<int, 3>

const int INF = 0x3f3f3f3f, mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<PII> pairs(n);
        for (int i = 0; i < n; ++i) {
            cin >> pairs[i].fi >> pairs[i].se;
        }

        sort(pairs.begin(), pairs.end(), [&](const PII &a, const PII &b) {
            return a.fi > b.fi;
        });

        int res = INF;
        for (int i = 0; i <= n - k; ++i) {
            int sum = 0;
            for (int j = 0; j < k; ++j) {
                sum += pairs[i + j].se;
            }
            res = min(res, pairs[i].fi * sum);
        }

        cout << res << endl;
    }

    return 0;
}