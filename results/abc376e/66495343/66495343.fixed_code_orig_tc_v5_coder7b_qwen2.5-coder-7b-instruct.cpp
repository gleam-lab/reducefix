#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

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

        for (int i = 1; i <= n; i++) {
            sa[i] = {a[i], b[i]};
        }

        sort(sa + 1, sa + n + 1);
        sort(b + 1, b + n + 1, greater<int>());

        int res = INF, sum = 0;
        for (int i = 1; i <= k; i++) {
            if (i == k) {
                res = min(res, sa[i].fi * (sum + b[i]));
            } else {
                sum += b[i];
                res = min(res, sa[i].fi * sum);
            }
        }

        cout << res << endl;
    }

    return 0;
}