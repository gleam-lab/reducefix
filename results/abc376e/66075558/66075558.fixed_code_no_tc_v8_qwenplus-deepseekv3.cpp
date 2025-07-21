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
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            b[i].first = b[a[i].second].first;
        }
        priority_queue<int> pq;
        int current_sum = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = current_sum + b[i].first;
            pq.push(b[i].first);
            current_sum += b[i].first;
            if (pq.size() > k - 1) {
                current_sum -= pq.top();
                pq.pop();
            }
        }
        int ans = inf;
        for (int i = k; i <= n; i++) {
            ans = min(ans, a[i].first * (sum[i - 1] + b[i].first));
        }
        cout << ans << '\n';
    }
    return 0;
}