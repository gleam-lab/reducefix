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
    cin.tie(0);
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
        priority_queue<int> pq;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int current_sum = sum + b[i];
            if (pq.size() == k - 1) {
                ans = min(ans, a[i].first * current_sum);
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