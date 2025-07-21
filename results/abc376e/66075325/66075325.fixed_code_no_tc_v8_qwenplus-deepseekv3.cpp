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
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        vector<int> B(n);
        for (int i = 0; i < n; i++) {
            B[i] = b[a[i].second];
        }
        int ans = inf;
        priority_queue<int> pq;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int current_sum = sum + B[i];
            if (pq.size() == k - 1) {
                ans = min(ans, a[i].first * current_sum);
            }
            pq.push(B[i]);
            sum += B[i];
            if (pq.size() > k - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}