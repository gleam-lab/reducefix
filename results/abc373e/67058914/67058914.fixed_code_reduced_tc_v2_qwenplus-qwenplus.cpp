#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
    }

    vector<ll> res(N);

    // Sort the candidates by current votes
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i].first < A[j].first; });

    // Compute prefix sums of the sorted votes
    vector<ll> sorted_votes(N);
    for (int i = 0; i < N; ++i) {
        sorted_votes[i] = A[idx[i]].first;
    }
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_votes[i];
    }

    ll total_remaining = K - prefix_sum[N];

    auto count_needed = [&](ll x, int pos) -> ll {
        ll my_vote = sorted_votes[pos] + x;
        int l = 0, r = pos;
        while (l < r) {
            int mid = (l + r) / 2;
            if (sorted_votes[mid] < my_vote) l = mid + 1;
            else r = mid;
        }
        return l;
    };

    for (int i = 0; i < N; ++i) {
        int id = idx[i];
        ll base = A[id].first;

        // Already enough?
        int higher = N - i;
        if (higher <= M) {
            res[id] = 0;
            continue;
        }

        // Binary search on needed additional votes
        ll left = 0, right = K - base + 1;
        while (left < right) {
            ll mid = (left + right) / 2;
            ll my_total = base + mid;
            // Find how many have strictly less than my_total
            int cnt = lower_bound(sorted_votes.begin(), sorted_votes.begin() + i, my_total) - sorted_votes.begin();
            // Need to make sure at most M-1 candidates have more
            // So we want that (number of candidates with >= my_total) < M
            int higher_equal = N - cnt;
            if (higher_equal <= M - 1) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Check if it's possible
        ll required = left;
        if (base + required > sorted_votes[N - 1]) {
            res[id] = required;
        } else {
            // Additional check: need enough budget
            ll my_total = base + required;
            int cnt = lower_bound(sorted_votes.begin(), sorted_votes.begin() + i, my_total) - sorted_votes.begin();
            ll extra = 0;
            for (int j = cnt; j < i; ++j) {
                if (sorted_votes[j] < my_total) continue;
                extra += (my_total - sorted_votes[j]);
            }
            if (extra <= total_remaining) {
                res[id] = required;
            } else {
                res[id] = -1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}