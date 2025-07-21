#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<double, int>
#define fi first
#define se second
#define arr array<int, 3>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[N], b[N];
PII ra[N]; // Ratio array

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            ra[i] = {static_cast<double>(a[i]) / b[i], i};
        }

        sort(ra + 1, ra + n + 1, [&](const PII &p1, const PII &p2) {
            return p1.fi > p2.fi;
        });

        int res = INF, sum = 0;
        priority_queue<int> pq;

        for (int i = 1; i <= n; i++) {
            if (i <= k) {
                sum += b[ra[i].se];
                pq.push(-b[ra[i].se]);
            } else {
                int big = -pq.top();
                pq.pop();
                sum -= big;
                sum += b[ra[i].se];
                pq.push(-b[ra[i].se]);
            }
            if (i >= k) {
                res = min(res, a[ra[i].se] * sum);
            }
        }

        cout << res << endl;
    }

    return 0;
}