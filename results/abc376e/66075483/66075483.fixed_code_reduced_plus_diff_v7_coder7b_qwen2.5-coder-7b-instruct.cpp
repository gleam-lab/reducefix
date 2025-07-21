#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

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
            b[i].second = i;
        }

        // Sort based on the index to maintain order after sorting by value
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        
        // Initialize the first window
        for (int i = 0; i < k; ++i) {
            pq.push(b[a[i].second].first);
            sum += b[a[i].second].first;
        }

        int ans = inf;
        for (int i = k; i < n; ++i) {
            ans = min(ans, (long long)a[i].first * sum);
            sum -= pq.top();
            pq.pop();
            pq.push(b[a[i].second].first);
            sum += b[a[i].second].first;
        }

        // Check for the last window
        ans = min(ans, (long long)a[n-1].first * sum);

        cout << ans << '\n';
    }

    return 0;
}