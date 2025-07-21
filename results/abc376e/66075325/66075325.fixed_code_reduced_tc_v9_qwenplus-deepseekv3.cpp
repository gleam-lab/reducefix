#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&a](int i, int j) {
            return a[i].first < a[j].first;
        });
        
        vector<int> sorted_a(n), sorted_b(n);
        for (int i = 0; i < n; i++) {
            sorted_a[i] = a[indices[i]].first;
            sorted_b[i] = b[indices[i]];
        }
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; i++) {
            if (pq.size() < k - 1) {
                pq.push(sorted_b[i]);
                sum += sorted_b[i];
            } else if (!pq.empty() && sorted_b[i] < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += sorted_b[i];
                pq.push(sorted_b[i]);
            }
            if (i >= k - 1) {
                int current_sum = sum + sorted_b[i];
                ans = min(ans, sorted_a[i] * current_sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}