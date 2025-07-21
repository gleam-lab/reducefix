#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

int n, k, t;
pair<int, int> a[N], b[N];
priority_queue<int> pq; // max-heap to keep the smallest K-1 elements

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
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
        while (!pq.empty()) pq.pop();
        int sum = 0;
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            int current_sum = sum + b[i].first;
            if (pq.size() == k - 1) {
                ans = min(ans, current_sum * a[i].first);
            }
            pq.push(b[i].first);
            sum += b[i].first;
            if (pq.size() > k - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}