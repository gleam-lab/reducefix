#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define arr array<int, 3>

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1), b(n + 1);
        vector<PII> items(n + 1);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        // Pair up A and B arrays and sort by A
        for (int i = 1; i <= n; ++i) {
            items[i] = {a[i], b[i]};
        }
        sort(items.begin() + 1, items.begin() + n + 1); // Sort by A

        int res = numeric_limits<int>::max(), sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to keep track of smallest K B-values

        for (int i = 1; i <= n; ++i) {
            if (i <= k) {
                sum += items[i].se;
                pq.push(items[i].se);
            } else {
                // Maintain only K elements in the heap
                if (pq.size() > k - 1) {
                    sum -= pq.top();
                    pq.pop();
                }
                sum += items[i].se;
                pq.push(items[i].se);
            }

            if (pq.size() == k) {
                res = min(res, items[i].fi * sum);
            }
        }

        cout << res << "\n";
    }

    return 0;
}