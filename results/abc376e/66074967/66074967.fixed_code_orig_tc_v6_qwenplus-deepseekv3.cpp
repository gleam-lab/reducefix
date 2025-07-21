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
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i].second;
        }
        
        sort(arr.begin(), arr.end());
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; i++) {
            int current_max = arr[i].first;
            sum += arr[i].second;
            pq.push(arr[i].second);
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = min(ans, current_max * sum);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}