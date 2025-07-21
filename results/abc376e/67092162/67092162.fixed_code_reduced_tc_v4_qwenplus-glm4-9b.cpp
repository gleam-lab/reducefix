#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int a[maxN], b[maxN];
pair<int, int> p[maxN];
vector<pair<int, int>> pq; // Priority queue to store negative of sum for min-heap behavior

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        int sum = 0;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) {
            p[i].first = a[i];
            p[i].second = b[i];
        }
        sort(p, p + n, cmp);

        // Calculate initial sum of B's for the first k elements
        for (int i = 0; i < k; ++i) {
            sum += p[i].second;
            pq.push_back({-p[i].second - a[i], p[i].second}); // Push negative sum to simulate min-heap
        }

        int ans = INT_MAX;
        // Iterate over each element from k to n
        for (int i = k; i < n; ++i) {
            sum += p[i].second;
            // Maintain the sum of B's of the k largest A's seen so far
            while (pq.size() < k) {
                pq.push_back({-p[i].second - a[i], p[i].second});
            }
            if (p[i].second >= -pq.front().second) {
                sum += pq.front().first;
                pq.pop_front();
            }
            pq.push_back({-p[i].second - a[i], p[i].second});
            ans = min(ans, sum * a[i]);
        }

        cout << ans << "\n";
    }
    return 0;
}