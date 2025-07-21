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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        sort(a.begin(), a.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_b = b[a[i].second];
            int current_a = a[i].first;
            
            if (min_heap.size() < k - 1) {
                min_heap.push(current_b);
                sum += current_b;
            } else {
                if (k == 1) {
                    ans = min(ans, current_a * current_b);
                } else {
                    ans = min(ans, current_a * (sum + current_b));
                }
                if (!min_heap.empty() && current_b > min_heap.top()) {
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