#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define arr array<int, 3>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[N], b[N];
int idx[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            idx[i] = i;
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        sort(idx + 1, idx + 1 + n, [&](int x, int y) { return a[x] < a[y]; });

        int res = INF, sum = 0, max_a = 0;

        for (int i = 1; i <= n; i++) {
            int cur_idx = idx[i];
            int cur_a = a[cur_idx];
            int cur_b = b[cur_idx];

            if (i <= k) {
                sum += cur_b;
                max_a = max(max_a, cur_a);
                continue;
            }

            sum -= b[idx[i - k]];
            sum += cur_b;
            max_a = max(max_a, cur_a);

            res = min(res, max_a * sum);
        }

        cout << res << endl;
    }

    return 0;
}