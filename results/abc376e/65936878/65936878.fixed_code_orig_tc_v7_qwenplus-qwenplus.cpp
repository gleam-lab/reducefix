#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].f;
        for (int i = 0; i < n; ++i) cin >> v[i].s;

        // Sort by A_i
        sort(v.begin(), v.end());

        priority_queue<int> q;
        int sum_b = 0;
        for (int i = 0; i < k - 1; ++i) {
            sum_b += v[i].s;
            q.push(v[i].s);
        }

        int ans = 1e18;
        for (int i = k - 1; i < n; ++i) {
            // Current candidate is the i-th element as max(A_i)
            if ((int)q.size() < k - 1) {
                // This should not happen if logic is correct
                sum_b += v[i].s;
                q.push(v[i].s);
            } else {
                if (q.empty()) {
                    sum_b += v[i].s;
                    q.push(v[i].s);
                } else {
                    if (q.top() > v[i].s) {
                        sum_b += v[i].s - q.top();
                        q.pop();
                        q.push(v[i].s);
                    }
                }
            }
            ans = min(ans, sum_b * v[i].f);
        }
        cout << ans << '\n';
    }

    return 0;
}