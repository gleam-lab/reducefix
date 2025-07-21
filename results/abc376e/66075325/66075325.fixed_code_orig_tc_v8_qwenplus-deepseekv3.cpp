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
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_a = ab[i].first;
            int current_b = ab[i].second;
            
            if (min_heap.size() < k - 1) {
                min_heap.push(current_b);
                sum += current_b;
            } else {
                ans = min(ans, current_a * (sum + current_b));
                if (k > 1 && current_b > min_heap.top()) {
                    sum -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(current_b);
                    sum += current_b;
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}