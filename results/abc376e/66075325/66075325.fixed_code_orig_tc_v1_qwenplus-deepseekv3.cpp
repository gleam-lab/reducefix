#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N], b[N];

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
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a, a + n);
        vector<int> B_sorted(n);
        for (int i = 0; i < n; ++i) {
            B_sorted[i] = b[a[i].second].first;
        }
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        vector<int> prefix_sum(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            if (min_heap.size() < k) {
                min_heap.push(B_sorted[i]);
                sum += B_sorted[i];
            } else if (min_heap.top() < B_sorted[i]) {
                sum -= min_heap.top();
                min_heap.pop();
                min_heap.push(B_sorted[i]);
                sum += B_sorted[i];
            }
            prefix_sum[i] = sum;
        }
        
        int ans = inf;
        for (int i = k - 1; i < n; ++i) {
            int current_max_A = a[i].first;
            int current_sum_B = prefix_sum[i - k + 1];
            ans = min(ans, current_max_A * current_sum_B);
        }
        
        cout << ans << '\n';
    }
    return 0;
}