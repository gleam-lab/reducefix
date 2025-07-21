#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
pair<int, int> a[N], b[N];
int bb[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> bb[i];
        }
        
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            b[i] = {bb[a[i].second], a[i].second};
        }
        
        int ans = 1e18;
        priority_queue<int> pq;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (pq.size() < k - 1) {
                pq.push(b[i].first);
                sum += b[i].first;
            } else if (!pq.empty() && pq.top() > b[i].first) {
                sum -= pq.top();
                pq.pop();
                pq.push(b[i].first);
                sum += b[i].first;
            }
            
            if (i >= k - 1) {
                ans = min(ans, a[i].first * (sum + b[i].first));
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}