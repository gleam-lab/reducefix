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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Create sorted version of A to help determine relative positions
    vector<pair<ll, int>> sorted_A(N);
    for (int i = 0; i < N; ++i)
        sorted_A[i] = {A[i], i};
    sort(all(sorted_A));

    // Prepare prefix sums of the sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i].first;

    vector<ll> result(N, -1);

    // For each candidate, binary search on minimum additional votes needed
    for (int idx = 0; idx < N; ++idx) {
        ll low = 0, high = K;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total_needed = 0;
            ll target_vote = A[idx] + mid;

            // Find how many candidates currently have more than our target vote
            // and ensure at most M-1 can remain after this addition
            int l = 0, r = N - 1;
            int better_count = 0;

            // Binary search to find number of candidates with strictly greater votes
            while (l <= r) {
                int m = (l + r) / 2;
                if (sorted_A[m].first > target_vote)
                    better_count = N - m, r = m - 1;
                else
                    l = m + 1;
            }

            if (better_count < M) {
                // Already good, no need for further action
                ans = mid;
                high = mid - 1;
            } else {
                // Need to block at least (better_count - (M - 1)) candidates from having more votes
                // We choose the top (better_count - M + 1) candidates that are above us,
                // and bring their votes down to at most equal to ours

                int start_idx = N - better_count;
                int end_idx = min(N, start_idx + (better_count - M + 1));
                ll required = (prefix[end_idx] - prefix[start_idx]) - (target_vote * (end_idx - start_idx));
                if (required <= K - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        if (ans > K)
            result[idx] = -1;
        else
            result[idx] = (ans == -1) ? -1 : ans;
    }

    for (ll x : result)
        cout << x << ' ';
    cout << '\n';
}