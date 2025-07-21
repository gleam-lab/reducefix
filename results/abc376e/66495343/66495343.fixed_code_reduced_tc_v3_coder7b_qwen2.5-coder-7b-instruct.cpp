#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define fi first
#define se second

const int INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[200010], b[200010];
PII sa[200010];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++)
            cin >> b[i];

        for (int i = 1; i <= n; i++)
            sa[i] = {a[i], b[i]};

        sort(sa + 1, sa + 1 + n);

        int res = INF, sum = 0;

        // Calculate the initial sum of the first k elements of B
        for (int i = 1; i <= k; i++)
            sum += sa[i].se;

        // Initialize the result with the product of the maximum element and the sum
        res = min(res, sa[k].fi * sum);

        // Slide the window across the sorted array
        for (int i = k + 1; i <= n; i++) {
            sum -= sa[i - k].se;
            sum += sa[i].se;
            res = min(res, sa[i].fi * sum);
        }

        cout << res << endl;
    }

    return 0;
}