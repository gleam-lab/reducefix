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
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> pairs[i].second;
        }
        sort(pairs.begin(), pairs.end());
        
        priority_queue<int> max_heap;
        int sum = 0;
        vector<int> prefix_sum(n);
        
        for (int i = 0; i < n; ++i) {
            if (max_heap.size() < k - 1) {
                max_heap.push(pairs[i].second);
                sum += pairs[i].second;
            } else if (!max_heap.empty() && pairs[i].second < max_heap.top()) {
                sum -= max_heap.top();
                max_heap.pop();
                max_heap.push(pairs[i].second);
                sum += pairs[i].second;
            }
            prefix_sum[i] = sum;
        }
        
        int ans = inf;
        for (int i = k - 1; i < n; ++i) {
            int current_sum = prefix_sum[i - 1] + pairs[i].second;
            ans = min(ans, pairs[i].first * current_sum);
        }
        cout << ans << '\n';
    }
    return 0;
}