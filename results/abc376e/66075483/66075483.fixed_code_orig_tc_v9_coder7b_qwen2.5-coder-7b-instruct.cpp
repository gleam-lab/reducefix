#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pii> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        // Sort by A[i] in descending order
        sort(a.begin(), a.end(), greater<pii>());
        // Sort by B[i] in ascending order
        sort(b.begin(), b.end());

        long long ans = LLONG_MAX;
        priority_queue<int> pq;
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            pq.push(b[i].first);
            sum += b[i].first;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = min(ans, static_cast<long long>(a[i].first) * sum);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}