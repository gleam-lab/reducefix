#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<ll> A(N), B(N);
        for (auto& x : A) cin >> x;
        for (auto& x : B) cin >> x;

        vector<pair<ll, ll>> AB(N);
        for (int i = 0; i < N; ++i) {
            AB[i] = {A[i], B[i]};
        }

        // Sort AB by A[i]
        sort(AB.begin(), AB.end());

        // Use a max heap to keep track of smallest K B values
        priority_queue<ll> pq;
        ll sumB = 0;

        // Initialize the first K elements
        for (int i = 0; i < K; ++i) {
            pq.push(AB[i].second);
            sumB += AB[i].second;
        }

        ll ans = AB[K - 1].first * sumB;

        // Process the rest
        for (int i = K; i < N; ++i) {
            if (AB[i].second < pq.top()) {
                sumB -= pq.top();
                pq.pop();
                pq.push(AB[i].second);
                sumB += AB[i].second;
            }
            ans = min(ans, AB[i].first * sumB);
        }

        cout << ans << "\n";
    }

    return 0;
}