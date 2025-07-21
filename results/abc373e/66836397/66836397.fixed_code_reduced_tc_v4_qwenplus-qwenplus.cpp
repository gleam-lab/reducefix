#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Prepare sorted list of votes
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // Prefix sum of sorted_A
    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];

    auto compute_needed_votes = [&](ll idx) {
        ll a_i = A[idx];

        // Binary search on additional votes needed
        ll low = 0;
        ll high = K + 1;
        ll answer = INF;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_votes = a_i + mid;
            ll remaining = K - mid;

            if (remaining < 0) {
                low = mid + 1;
                continue;
            }

            // Find how many candidates have strictly more than total_votes
            ll cnt = N - (upper_bound(sorted_A.begin(), sorted_A.end(), total_votes) - sorted_A.begin());

            if (cnt >= M) {
                answer = mid;
                high = mid - 1;
            } else {
                // Need to increase this candidate's votes more
                low = mid + 1;
            }
        }

        return answer;
    };

    vector<ll> result(N);
    for (ll i = 0; i < N; ++i) {
        ll needed = compute_needed_votes(i);
        if (needed > K)
            result[i] = -1;
        else
            result[i] = needed;
    }

    for (ll i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}