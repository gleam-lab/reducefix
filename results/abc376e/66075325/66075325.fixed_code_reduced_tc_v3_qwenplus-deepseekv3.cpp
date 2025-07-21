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
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int ans = inf;
        
        for (int i = n - 1; i >= 0; --i) {
            int current_a = a_b[i].first;
            int current_b = a_b[i].second;
            min_heap.push(current_b);
            sum += current_b;
            
            if (min_heap.size() > k) {
                sum -= min_heap.top();
                min_heap.pop();
            }
            
            if (min_heap.size() == k) {
                ans = min(ans, current_a * sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}