#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int n, k;
vector<pair<int, int>> a, b;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.clear();
        b.clear();
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            a.push_back({val, i});
        }
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            b.push_back({val, i});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), [](const pair<int, int>& p, const pair<int, int>& q) {
            return p.first < q.first;
        });

        int32_t ans = LLONG_MAX;
        int sum = 0;

        // Start from the end of the arrays to find the minimum possible value
        for (int i = n - 1; i >= 0 && a[i].first <= b[i].first; --i) {
            sum += b[i].first;
            // We need at least k elements to form a valid subset
            if (i >= n - k + 1) {
                ans = min(ans, (sum + b[i + 1].first) * a[i].first);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}