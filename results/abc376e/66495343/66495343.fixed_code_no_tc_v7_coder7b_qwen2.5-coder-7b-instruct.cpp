#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

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

        for (int i = 1; i <= n; i++) {
            sa[i] = {a[i], b[i]};
        }

        // Sort based on the product of a and b in descending order
        sort(sa + 1, sa + 1 + n, [](const PII &p1, const PII &p2) {
            return p1.fi * p2.se > p2.fi * p1.se;
        });

        int res = INF, sum = 0;
        for (int i = 1; i <= k; i++) {
            sum += sa[i].se;
        }
        res = min(res, sa[k].fi * sum);

        for (int i = k + 1; i <= n; i++) {
            sum -= sa[i - k].se;
            sum += sa[i].se;
            res = min(res, sa[i].fi * sum);
        }

        cout << res << endl;
    }

    return 0;
}