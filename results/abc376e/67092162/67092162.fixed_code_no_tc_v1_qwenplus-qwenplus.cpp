#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; ++i) cin >> items[i].first;
        for (int i = 0; i < n; ++i) cin >> items[i].second;

        // Sort items by A_i in ascending order
        sort(items.begin(), items.end());

        // Min-heap to maintain the K largest B_i values
        priority_queue<int, vector<int>, greater<>> pq;
        long long sum_b = 0;
        for (int i = 0; i < k; ++i) {
            sum_b += items[i].second;
            pq.push(items[i].second);
        }

        long long ans = 1LL * items[k - 1].first * sum_b;

        for (int i = k; i < n; ++i) {
            if (items[i].second > pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].second);
                sum_b += items[i].second;
            }
            ans = min(ans, 1LL * items[i].first * sum_b);
        }

        cout << ans << "\n";
    }

    return 0;
}