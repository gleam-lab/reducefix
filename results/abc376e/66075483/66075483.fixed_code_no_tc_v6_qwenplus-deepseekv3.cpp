#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9;
const int inf = 0x3f3f3f3f3f3f3f3f;

pair<int, int> a[N];
int b[N];
int prefix_sum[N];

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
            cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            b[i] = b[a[i].second];
        }
        
        priority_queue<int> pq;
        int sum = 0;
        for (int i = 1; i <= k - 1; ++i) {
            pq.push(b[i]);
            sum += b[i];
        }
        prefix_sum[k - 1] = sum;
        for (int i = k; i <= n; ++i) {
            if (b[i] < pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += b[i];
                pq.push(b[i]);
            }
            prefix_sum[i] = sum;
        }
        
        int ans = inf;
        for (int i = k; i <= n; ++i) {
            ans = min(ans, a[i].first * (prefix_sum[i - 1] + b[i]));
        }
        cout << ans << '\n';
    }
    return 0;
}