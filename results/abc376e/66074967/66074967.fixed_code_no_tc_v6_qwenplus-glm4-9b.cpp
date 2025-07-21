#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            a[i].second = b[i].first;
        }

        sort(a.begin(), a.end(), [](const pair<int, int>& left, const pair<int, int>& right) {
            return left.first < right.first;
        });

        long long ans = LLONG_MAX;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i].second;
            if (i >= k - 1) {
                ans = min(ans, sum * a[i].first);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}