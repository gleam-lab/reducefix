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
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].second;
        }
        
        sort(ab.begin(), ab.end());
        
        priority_queue<int> max_heap;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_a = ab[i].first;
            int current_b = ab[i].second;
            
            if (max_heap.size() < k - 1) {
                max_heap.push(current_b);
                sum += current_b;
            } else if (!max_heap.empty() && current_b < max_heap.top()) {
                sum -= max_heap.top();
                max_heap.pop();
                max_heap.push(current_b);
                sum += current_b;
            }
            
            if (max_heap.size() == k - 1) {
                ans = min(ans, current_a * (sum + current_b));
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}