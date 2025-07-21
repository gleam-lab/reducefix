#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        pq = {};
        long long sum = 0, ans = LLONG_MAX;

        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            pq.push({b[i], a[i]});
        }

        for (int i = 0; i < k; ++i) {
            sum += pq.top().first;
            pq.pop();
        }

        ans = min(ans, sum * pq.top().second);

        while (!pq.empty()) {
            auto [min_b, max_a] = pq.top(); pq.pop();
            sum -= min_b;
            pq.push({min_b, max_a});
            sum += pq.top().first;
            ans = min(ans, sum * pq.top().second);
        }

        cout << ans << "\n";
    }

    return 0;
}