#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
const int INF = 1e18;

int n, k, t;
pair<int, int> a[200005], b[200005];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        
        priority_queue<int> pq;
        int sum = 0;
        for (int i = 1; i <= k; i++) {
            pq.push(b[i].first);
            sum += b[i].first;
        }
        
        int ans = INF;
        for (int i = k; i <= n; i++) {
            ans = min(ans, (long long)a[i].first * sum);
            
            sum += b[i].first - pq.top();
            pq.pop();
            pq.push(b[i].first);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}