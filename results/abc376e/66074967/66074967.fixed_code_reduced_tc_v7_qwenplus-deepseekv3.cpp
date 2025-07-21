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
        
        int ans = inf;
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap to keep largest K-1 elements
        int sum = 0;
        
        for (int i = 0; i < n; ++i) {
            int current_a = elements[i].first;
            int current_b = elements[i].second;
            
            if (pq.size() < k) {
                pq.push(current_b);
                sum += current_b;
            } else if (current_b > pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(current_b);
                sum += current_b;
            }
            
            if (pq.size() == k) {
                ans = min(ans, current_a * sum);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}