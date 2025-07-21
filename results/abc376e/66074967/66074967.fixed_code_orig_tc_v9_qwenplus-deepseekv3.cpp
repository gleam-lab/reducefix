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
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; i++) {
            cin >> ab[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> ab[i].second;
        }
        
        sort(ab.begin(), ab.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        int res = inf;
        
        for (int i = n-1; i >= 0; i--) {
            sum += ab[i].second;
            pq.push(ab[i].second);
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                res = min(res, ab[i].first * sum);
            }
        }
        
        cout << res << '\n';
    }
    return 0;
}