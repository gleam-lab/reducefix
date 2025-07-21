#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200010], b[200010];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        priority_queue<pair<int, int>> pq; // Max-heap to keep the smallest k-1 elements
        long long sum = 0, res = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            if (pq.size() < k) {
                pq.push({b[i], a[i]});
                sum += b[i];
            } else if (pq.top().first < b[i]) {
                // Only change if we find a larger b[i] than the smallest element in the heap
                sum = sum - pq.top().first + b[i];
                pq.push({b[i], a[i]});
                pq.pop();
            }
        }

        // Calculate the minimum result by considering all elements as the maximum in the subset
        while (!pq.empty()) {
            res = min(res, (long long)pq.top().second * sum);
            pq.pop();
        }

        cout << res << '\n';
    }

    return 0;
}