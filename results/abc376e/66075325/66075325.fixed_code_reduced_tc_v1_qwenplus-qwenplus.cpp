#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
        }

        // Sort elements by A values
        sort(a.begin(), a.end());

        // Reorder B based on sorted A
        vector<int> reordered_b(n);
        for (int i = 0; i < n; ++i) {
            reordered_b[i] = b[a[i].second].first;
        }

        // Use min-heap to maintain top K smallest B values
        priority_queue<int, vector<int>, greater<>> pq;
        int sum = 0;
        int res = 1e18; // Initialize with large number

        for (int i = 0; i < n; ++i) {
            pq.push(reordered_b[i]);
            sum += reordered_b[i];

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                res = min(res, a[i].first * sum);
            }
        }

        cout << res << '\n';
    }

    return 0;
}