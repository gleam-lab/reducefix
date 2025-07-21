#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define int long long
const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }

        // Sort arrays based on A_i values
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Initialize variables
        int ans = inf;
        int sum_b = 0;
        priority_queue<int> pq;

        // Sliding window technique
        for (int i = 0; i < n; i++) {
            pq.push(b[i].first);
            sum_b += b[i].first;

            // Maintain window size of K
            if (pq.size() > k) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Calculate the result for the current window
            if (pq.size() == k) {
                ans = min(ans, (long long)a[i].first * sum_b);
            }
        }

        cout << ans << endl;
    }
    return 0;
}