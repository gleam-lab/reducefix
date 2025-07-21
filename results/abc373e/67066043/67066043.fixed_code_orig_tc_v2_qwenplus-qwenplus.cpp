#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Sort the original votes
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    // Prefix sum of sorted votes
    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i)
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];

    vector<ll> result(N, -1);

    // Precompute positions for binary search
    vector<int> indices(N);
    iota(all(indices), 0);
    sort(all(indices), [&](int x, int y) { return A[x] < A[y]; });

    // Sort values for efficient querying
    vector<ll> sorted_values = A;
    sort(all(sorted_values));

    for (int idx : indices) {
        ll low = 0, high = K;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = A[idx] + mid;

            // Find how many candidates have votes > target
            int pos = upper_bound(all(sorted_values), target) - sorted_values.begin();

            // We must ensure that at most (M - 1) candidates have more votes
            if (N - pos >= M) {
                // Need to reduce those who have > target to < M candidates
                int start = max(0, N - M + 1); // Start of top M candidates we may need to cap
                ll required_votes = 0;

                // Count how many votes needed to bring top (N - pos) down to M - 1
                int limit = N - (M - 1);
                if (limit > pos) {
                    int left = lower_bound(all(sorted_values), target + 1) - sorted_values.begin();
                    if (left > pos)
                        required_votes = (left - pos) * (target + 1) - (prefix_sum[left] - prefix_sum[pos]);
                    else
                        required_votes = 0;

                    // Exclude self from count if necessary
                    for (int j = 0; j < N; ++j) {
                        if (j == idx) continue;
                        if (A[j] > target) required_votes += max(0LL, A[j] - target);
                    }
                }

                if (required_votes <= K - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        result[idx] = (ans == -1 ? -1 : ans);
    }

    for (ll val : result)
        cout << val << ' ';
    cout << '\n';
}