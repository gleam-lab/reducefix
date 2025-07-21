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
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        vector<int> sorted_b(n);
        for (int i = 0; i < n; i++) {
            sorted_b[i] = b[a[i].second];
        }
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; i++) {
            int current_a = a[i].first;
            int current_b = sorted_b[i];
            if (pq.size() < k - 1) {
                pq.push(current_b);
                sum += current_b;
            } else {
                if (k == 1) {
                    ans = min(ans, current_a * current_b);
                } else {
                    ans = min(ans, current_a * (sum + current_b));
                    if (current_b < pq.top()) {
                        sum -= pq.top();
                        pq.pop();
                        sum += current_b;
                        pq.push(current_b);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}