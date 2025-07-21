#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        for (int i = 1; i <= n; ++i) {
            sa[i] = {a[i], b[i]};
        }

        sort(sa + 1, sa + n + 1);

        if (k == 1) {
            int res = LLONG_MAX;
            for (int i = 1; i <= n; ++i) {
                res = min(res, sa[i].fi * sa[i].se);
            }
            cout << res << endl;
            continue;
        }

        int res = LLONG_MAX;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> q; // min-heap to keep the largest (k-1) elements

        for (int i = 1; i <= n; ++i) {
            if (i <= k - 1) {
                sum += sa[i].se;
                q.push(sa[i].se);
                continue;
            }

            int current_max_a = sa[i].fi;
            sum += sa[i].se;
            q.push(sa[i].se);

            if (q.size() > k - 1) {
                sum -= q.top();
                q.pop();
            }

            res = min(res, current_max_a * (sum));
        }

        cout << res << endl;
    }
    return 0;
}