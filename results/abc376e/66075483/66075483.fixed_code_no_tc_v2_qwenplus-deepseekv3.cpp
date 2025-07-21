#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
pair<int, int> a[N];
int b[N];

signed main() {
    ios::sync_with_stdio(false);
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
        for (int i = 0; i < n; ++i) {
            a[i].second = b[a[i].second];
        }
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            if (pq.size() < k - 1) {
                pq.push(a[i].second);
                sum += a[i].second;
            } else if (!pq.empty() && pq.top() > a[i].second) {
                sum -= pq.top();
                pq.pop();
                pq.push(a[i].second);
                sum += a[i].second;
            }
            if (pq.size() == k - 1) {
                ans = min(ans, (sum + a[i].second) * a[i].first);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}