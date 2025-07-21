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
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        sort(a.begin(), a.end());
        vector<int> sorted_b(n);
        for (int i = 0; i < n; ++i) {
            sorted_b[i] = b[a[i].second].first;
        }

        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int ans = inf;

        for (int i = 0; i < n; ++i) {
            if (min_heap.size() < k - 1) {
                min_heap.push(sorted_b[i]);
                sum += sorted_b[i];
            } else {
                if (k == 1) {
                    ans = min(ans, sorted_b[i] * a[i].first);
                } else {
                    if (sorted_b[i] > min_heap.top()) {
                        sum -= min_heap.top();
                        min_heap.pop();
                        min_heap.push(sorted_b[i]);
                        sum += sorted_b[i];
                    }
                    ans = min(ans, (sum + sorted_b[i]) * a[i].first);
                }
            }
        }

        if (k == 1) {
            ans = inf;
            for (int i = 0; i < n; ++i) {
                ans = min(ans, sorted_b[i] * a[i].first);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}