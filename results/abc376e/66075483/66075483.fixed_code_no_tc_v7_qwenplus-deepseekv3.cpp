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
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }

        sort(a, a + n);

        vector<int> sorted_b(n);
        for (int i = 0; i < n; i++) {
            sorted_b[i] = b[a[i].second].first;
        }

        priority_queue<int> pq;
        int current_sum = 0;
        int ans = inf;

        for (int i = 0; i < n; i++) {
            if (pq.size() < k - 1) {
                pq.push(sorted_b[i]);
                current_sum += sorted_b[i];
            } else if (!pq.empty() && sorted_b[i] < pq.top()) {
                current_sum -= pq.top();
                pq.pop();
                pq.push(sorted_b[i]);
                current_sum += sorted_b[i];
            }
            if (pq.size() == k - 1) {
                ans = min(ans, (current_sum + sorted_b[i]) * a[i].first);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}