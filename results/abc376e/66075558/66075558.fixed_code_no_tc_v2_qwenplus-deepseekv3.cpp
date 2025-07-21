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
        vector<int> sorted_b(n);
        for (int i = 0; i < n; ++i) {
            sorted_b[i] = b[a[i].second];
        }
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            if (pq.size() < k - 1) {
                pq.push(sorted_b[i]);
                sum += sorted_b[i];
            } else {
                if (k > 1 && sorted_b[i] < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(sorted_b[i]);
                    sum += sorted_b[i];
                }
            }
            if (i >= k - 1) {
                ans = min(ans, a[i].first * (sum + sorted_b[i]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}