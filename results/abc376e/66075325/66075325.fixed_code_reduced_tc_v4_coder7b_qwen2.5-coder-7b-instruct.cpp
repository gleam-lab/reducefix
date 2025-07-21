#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define int long long
#define lowbit(x) x & (-x)

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n + 1), b(n + 1);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long total_sum = 0, ans = inf;

        // Read and store A and B arrays
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        // Sort A based on A[i]
        sort(a.begin(), a.end());

        // Initialize heap with first K elements of B
        for (int i = 1; i <= k; ++i) {
            pq.push(b[a[i].second].first);
            total_sum += b[a[i].second].first;
        }

        // Calculate initial result
        ans = min(ans, total_sum * a[k].first);

        // Iterate through the remaining elements
        for (int i = k + 1; i <= n; ++i) {
            // Remove the largest element from the current sum
            total_sum -= pq.top();
            pq.pop();

            // Add the next smallest element from B
            pq.push(b[a[i].second].first);
            total_sum += b[a[i].second].first;

            // Update the result
            ans = min(ans, total_sum * a[i].first);
        }

        cout << ans << endl;
    }
    return 0;
}