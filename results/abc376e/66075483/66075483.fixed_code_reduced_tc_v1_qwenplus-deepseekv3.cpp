#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
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
        vector<int> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        sort(a.begin(), a.end());
        vector<int> sorted_b(n);
        for (int i = 0; i < n; ++i) {
            sorted_b[i] = b[a[i].second];
        }
        
        if (k == 1) {
            int min_product = inf;
            for (int i = 0; i < n; ++i) {
                min_product = min(min_product, a[i].first * sorted_b[i]);
            }
            cout << min_product << '\n';
            continue;
        }
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            if (pq.size() == k - 1) {
                ans = min(ans, a[i].first * (sum + sorted_b[i]));
            }
            sum += sorted_b[i];
            pq.push(sorted_b[i]);
            if (pq.size() > k - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}