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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        vector<pair<int, int>> elements(n);
        for (int i = 0; i < n; ++i) {
            elements[i] = {a[i].first, b[i]};
        }
        sort(elements.begin(), elements.end());
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_a = elements[i].first;
            int current_b = elements[i].second;
            
            if (pq.size() < k - 1) {
                pq.push(current_b);
                sum += current_b;
            } else if (!pq.empty() && current_b < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(current_b);
                sum += current_b;
            }
            
            if (pq.size() == k - 1) {
                ans = min(ans, current_a * (sum + current_b));
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}