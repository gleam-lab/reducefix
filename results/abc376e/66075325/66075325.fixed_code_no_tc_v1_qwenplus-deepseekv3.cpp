#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;

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
            int current_a = a_b[i].first;
            int current_b = a_b[i].second;
            
            if (max_heap.size() < k - 1) {
                max_heap.push(current_b);
                sum += current_b;
            } else {
                if (!max_heap.empty() && current_b < max_heap.top()) {
                    sum -= max_heap.top();
                    max_heap.pop();
                    sum += current_b;
                    max_heap.push(current_b);
                }
            }
            
            if (max_heap.size() == k - 1) {
                ans = min(ans, current_a * (sum + current_b));
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}