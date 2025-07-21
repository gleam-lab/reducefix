#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
long long t, n, k, a[maxN], b[maxN];
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];

        // Sort A in descending order
        sort(a + 1, a + n + 1, greater<int>());
        // Sort B in ascending order
        sort(b + 1, b + n + 1);

        long long res = LLONG_MAX, sum = 0;
        pq.push(0);
        
        for (int i = 1; i <= n; ++i) {
            sum += b[i];
            pq.push(sum);
            
            // Keep the heap size no larger than K
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }

            // Calculate the result
            if (pq.size() == K) {
                res = min(res, static_cast<long long>(a[i]) * sum);
            }
        }

        cout << res << "\n";
    }
    return 0;
}