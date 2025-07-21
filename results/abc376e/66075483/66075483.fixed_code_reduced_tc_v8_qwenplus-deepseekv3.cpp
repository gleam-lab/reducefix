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
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        
        sort(a.begin(), a.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int ans = inf;
        
        for (int i = n - 1; i >= 0; --i) {
            if (min_heap.size() < k - 1) {
                min_heap.push(a[i].second);
                sum += a[i].second;
            } else if (k > 1 && a[i].second > min_heap.top()) {
                sum -= min_heap.top();
                min_heap.pop();
                min_heap.push(a[i].second);
                sum += a[i].second;
            }
            
            if (min_heap.size() == k - 1) {
                int current = a[i].first * (sum + a[i].second);
                if (current < ans) {
                    ans = current;
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}