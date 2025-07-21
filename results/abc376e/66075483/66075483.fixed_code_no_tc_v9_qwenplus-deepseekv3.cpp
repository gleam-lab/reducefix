#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N];
int b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            b[i] = b[a[i].second];
        }
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_max_a = a[i].first;
            int current_b = b[i];
            int current_sum = sum + current_b;
            
            if (pq.size() == k - 1) {
                ans = min(ans, current_max_a * current_sum);
            }
            
            pq.push(b[i]);
            sum += b[i];
            
            if (pq.size() > k - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}