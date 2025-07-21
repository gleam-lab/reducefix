#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) {
        cin >> a;
        K -= a;
    }

    // Create sorted version of A
    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i)
        sortedA[i] = {A[i], i};
    sort(all(sortedA));

    vector<ll> result(N, -1);

    // Prepare prefix sums
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sortedA[i].first;

    auto solve_for_candidate = [&](int idx) {
        ll low = 0, high = K + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_needed = 0;

            ll target_vote = A[idx] + mid;

            // Binary search to find how many candidates can have more than target_vote
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sortedA[m].first >= target_vote)
                    right = m;
                else
                    left = m + 1;
            }

            // We need at most M-1 candidates to have more votes than us
            int max_allowed_above = M - 1;
            int current_above = N - left;

            if (current_above > max_allowed_above) {
                // Need to increase our votes
                low = mid + 1;
                continue;
            }

            // Calculate minimum additional votes needed
            ll required = 0;
            int top_idx = left + max_allowed_above;

            if (top_idx >= N)
                top_idx = N - 1;

            // Make top M-1 candidates have at most target_vote
            required += (max_allowed_above + 1) * target_vote - (prefix[N] - prefix[left]);

            if (required <= K - mid) {
                // Valid assignment
                result[idx] = mid;
                high = mid - 1;
            } else {
                // Not enough remaining votes
                low = mid + 1;
            }
        }
    };

    for (int i = 0; i < N; ++i)
        solve_for_candidate(i);

    for (ll val : result)
        cout << (val == -1 ? -1 : val) << ' ';

    return 0;
}