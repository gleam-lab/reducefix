#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
    }

    // Original indices to restore the order at the end
    vector<int> originalIndex(N);
    iota(originalIndex.begin(), originalIndex.end(), 0);

    // Sort candidates by current vote count
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i].first < A[j].first; });

    // Create a sorted array of votes
    vector<ll> sorted_votes(N);
    for (int i = 0; i < N; ++i) {
        sorted_votes[i] = A[idx[i]].first;
    }

    // Prefix sum of sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + sorted_votes[i - 1];
    }

    // Binary search helper to find how many top candidates have votes > cur_val
    auto count_top = [&](ll cur_val) {
        int cnt = N - (upper_bound(sorted_votes.begin(), sorted_votes.end(), cur_val) - sorted_votes.begin());
        return cnt;
    };

    // Main logic for each candidate
    vector<ll> result(N);
    for (int i = 0; i < N; ++i) {
        int orig_pos = idx[i];  // original index of the current candidate

        ll lo = 0, hi = K;
        ll ans = -1;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            ll total = A[orig_pos].first + mid;

            // Total number of candidates with more than total votes
            int cnt = count_top(total);

            if (cnt >= M) {
                lo = mid + 1;
            } else {
                ans = mid;
                hi = mid - 1;
            }
        }

        result[orig_pos] = (ans == -1 ? -1 : ans);
    }

    // Output results in original order
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}