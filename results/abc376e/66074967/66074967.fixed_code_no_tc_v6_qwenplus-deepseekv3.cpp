#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
#define inf 1e18

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        vector<int> sorted_b(n);
        for (int i = 0; i < n; i++) {
            sorted_b[i] = b[a[i].second];
        }
        priority_queue<int> max_heap;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; i++) {
            int current_sum = sum + sorted_b[i];
            if (max_heap.size() == k - 1) {
                ans = min(ans, a[i].first * current_sum);
            }
            max_heap.push(sorted_b[i]);
            sum += sorted_b[i];
            if (max_heap.size() > k - 1) {
                sum -= max_heap.top();
                max_heap.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}