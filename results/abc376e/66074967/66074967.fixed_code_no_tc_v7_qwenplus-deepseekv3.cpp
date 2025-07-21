#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a_b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a_b[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a_b[i].second;
        }
        sort(a_b.begin(), a_b.end());
        priority_queue<int> max_heap;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            int current_sum = sum + a_b[i].second;
            ans = min(ans, a_b[i].first * current_sum);
            max_heap.push(a_b[i].second);
            sum += a_b[i].second;
            if (max_heap.size() >= k) {
                sum -= max_heap.top();
                max_heap.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}