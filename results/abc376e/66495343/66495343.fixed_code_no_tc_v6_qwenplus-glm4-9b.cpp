#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second

const int N = 2e5 + 10;

int a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<PII> sa(n + 1);
        for (int i = 1; i <= n; i++) {
            sa[i] = {a[i], b[i]};
        }

        // Sort by A_i descending first, B_i ascending in case of tie
        sort(sa.begin() + 1, sa.begin() + 1 + n, [](const PII &a, const PII &b) {
            if (a.fi != b.fi) return a.fi > b.fi;
            return a.se < b.se;
        });

        int res = LLONG_MAX;
        long long sum = 0;
        vector<long long> pq;
        for (int i = 1; i <= n; i++) {
            sum += sa[i].se;
            pq.push_back(sa[i].se);

            if (pq.size() > k) {
                sum -= pq.front();
                pq.erase(pq.begin());
            }

            if (pq.size() == k) {
                res = min(res, (long long)sa[i].fi * sum);
            }
        }

        cout << res << endl;
    }

    return 0;
}