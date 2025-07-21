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
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort based on A_i
        sort(a.begin(), a.end());

        // Create an array where B is ordered according to sorted A
        vector<int> sorted_b(n);
        for (int i = 0; i < n; ++i) {
            sorted_b[i] = b[a[i].second];
        }

        priority_queue<int> pq; // Max heap to keep track of the smallest K-1 B_i's
        int sum = 0;
        int res = inf;

        for (int i = 0; i < n; ++i) {
            if (pq.size() < k - 1) {
                pq.push(sorted_b[i]);
                sum += sorted_b[i];
            } else {
                if (k == 1) {
                    res = min(res, a[i].first * sorted_b[i]);
                } else {
                    res = min(res, a[i].first * (sum + sorted_b[i]));
                }
                if (!pq.empty() && sorted_b[i] < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(sorted_b[i]);
                    sum += sorted_b[i];
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}