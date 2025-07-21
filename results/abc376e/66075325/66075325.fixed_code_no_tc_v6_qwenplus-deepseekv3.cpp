#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N], bb[N];
int b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> bb[i].first;
            bb[i].second = i;
        }
        
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            b[i] = bb[a[i].second].first;
        }
        
        int ans = inf;
        priority_queue<int> max_heap;
        int sum = 0;
        
        for (int i = 1; i <= n; i++) {
            if (max_heap.size() < k - 1) {
                max_heap.push(b[i]);
                sum += b[i];
            } else if (!max_heap.empty() && b[i] < max_heap.top()) {
                sum -= max_heap.top();
                max_heap.pop();
                max_heap.push(b[i]);
                sum += b[i];
            }
            
            if (max_heap.size() == k - 1 && i >= k) {
                ans = min(ans, (sum + b[i]) * a[i].first);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}