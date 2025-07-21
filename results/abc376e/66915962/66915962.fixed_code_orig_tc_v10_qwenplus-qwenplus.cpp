#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<ll, ll>> AB(N);
        for (auto& [a, b] : AB) cin >> a;
        for (auto& [a, b] : AB) cin >> b;

        // Sort by A
        sort(AB.begin(), AB.end());

        priority_queue<ll> max_heap;  // To maintain smallest K B values (min-heap logic with negative)
        ll sum_B = 0;
        ll ans = numeric_limits<ll>::max();

        for (int i = 0; i < N; ++i) {
            auto [a, b] = AB[i];
            sum_B += b;
            max_heap.push(b);

            if (max_heap.size() > K) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == K) {
                ans = min(ans, a * sum_B);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}