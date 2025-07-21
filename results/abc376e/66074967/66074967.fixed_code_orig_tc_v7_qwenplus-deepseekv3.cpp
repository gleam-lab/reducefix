#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
        vector<pair<int, int>> elements(n);
        for (int i = 0; i < n; i++) {
            cin >> elements[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> elements[i].second;
        }
        
        sort(elements.begin(), elements.end());
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = n - 1; i >= 0; i--) {
            pq.push(elements[i].second);
            sum += elements[i].second;
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = min(ans, elements[i].first * sum);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}