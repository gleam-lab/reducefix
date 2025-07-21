#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N], b[N];
int sum[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            b[i].first = b[a[i].second].first;
        }
        
        priority_queue<int> pq;
        int current_sum = 0;
        int ans = inf;
        
        for (int i = 1; i <= n; ++i) {
            if (pq.size() < k - 1) {
                pq.push(b[i].first);
                current_sum += b[i].first;
            } else if (!pq.empty() && b[i].first < pq.top()) {
                current_sum -= pq.top();
                pq.pop();
                pq.push(b[i].first);
                current_sum += b[i].first;
            }
            
            if (i >= k) {
                ans = min(ans, a[i].first * (current_sum + b[i].first));
            } else if (i == k - 1) {
                ans = min(ans, a[i].first * current_sum);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}