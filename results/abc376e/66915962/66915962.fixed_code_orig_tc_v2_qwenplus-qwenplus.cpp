#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<ll, ll>> AB(N);
        for (int i = 0; i < N; ++i) cin >> AB[i].first;
        for (int i = 0; i < N; ++i) cin >> AB[i].second;

        // Sort by A ascending
        sort(AB.begin(), AB.end());

        // Maintain a min-heap of B values
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sumB = 0;
        ll ans = numeric_limits<ll>::max();

        for (int i = 0; i < N; ++i) {
            pq.push(AB[i].second);
            sumB += AB[i].second;

            if (pq.size() > K) {
                sumB -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                ans = min(ans, AB[i].first * sumB);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}