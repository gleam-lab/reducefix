#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    vector<ll> ans(N);

    // Sort by vote count ascending
    sort(A.begin(), A.end());

    // Prefix sums for binary search usage
    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + A[i - 1].first;
    }

    // Total used votes so far
    ll total_used = prefix[N];
    ll remaining = K - total_used;

    // Function to check if candidate at index 'i' can be guaranteed a win with 'add' extra votes
    auto compute_min_votes = [&](int i) -> ll {
        ll base = A[i].first;
        ll left = 0, right = remaining;
        ll res = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll new_score = base + mid;

            // Binary search to find how many candidates have votes > new_score
            int l = 0, r = N - 1;
            int cnt = 0;

            // Since A is sorted, we can use binary search
            int idx = upper_bound(A.begin(), A.end(), make_pair(new_score, N)) - A.begin();

            // Exclude self from count
            if (A[i].first >= new_score)
                idx--;

            if (idx >= N - M + 1) {
                // Already not enough candidates can beat us
                right = mid - 1;
                continue;
            }

            // Need to block top (M - 1) candidates above us
            int need_block = M - 1;
            int start = idx + 1;
            if (start >= N) {
                // No one beats us
                res = mid;
                right = mid - 1;
                continue;
            }

            // Distribute remaining votes greedily to prevent these candidates from beating us
            ll extra_needed = 0;
            int j = N - 1;
            while (j >= start && need_block > 0 && extra_needed <= remaining - mid) {
                ll target = max(new_score + 1LL, A[j].first);
                extra_needed += max(0LL, target - A[j].first);
                --j;
                --need_block;
            }

            if (extra_needed <= remaining - mid) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    };

    // Process each candidate
    for (int i = 0; i < N; ++i) {
        ans[A[i].second] = compute_min_votes(i);
    }

    // Output result
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}