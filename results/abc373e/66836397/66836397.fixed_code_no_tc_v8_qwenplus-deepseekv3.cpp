#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;

    ll remaining = K;
    for (ll a : A) remaining -= a;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];

    for (int i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll low = 0, high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll total = a_i + mid;

            // Find the number of candidates with votes > total
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), total);
            ll cnt_greater = sorted_A.end() - it;

            // If the candidate is already in the top M, no need for additional votes
            if (cnt_greater < M) {
                ans = mid;
                high = mid - 1;
                continue;
            }

            // Otherwise, calculate the required votes to ensure the candidate is in the top M
            ll required = 0;
            ll idx = it - sorted_A.begin();
            ll start = idx - (M - 1);
            if (start < 0) {
                // Not possible to have enough candidates with votes <= total
                low = mid + 1;
                continue;
            }

            // Sum of votes from sorted_A[start] to sorted_A[idx - 1] that need to be <= total
            ll sum = prefix_sum[idx] - prefix_sum[start];
            required = total * (idx - start) - sum;

            if (required <= remaining - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << " \n"[i == N - 1];
    }

    return 0;
}