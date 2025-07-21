#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int idx;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes < b.votes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    vector<Candidate> candidates(N);
    ll total = 0;

    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].idx = i;
        total += candidates[i].votes;
    }

    K -= total;
    vector<ll> result(N);

    // Sort candidates by current votes
    sort(candidates.begin(), candidates.end(), compare);

    // Prefix sum array
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    for (int i = 0; i < N; ++i) {
        int pos = i; // position in sorted list
        ll needed_votes = 0;

        // We binary search the minimum number of additional votes needed
        ll low = 0, high = K;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = candidates[pos].votes + mid;

            // Find how many candidates have more than our target
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (candidates[m].votes > target)
                    right = m;
                else
                    left = m + 1;
            }

            int rank = N - left;

            // If we are among top M, then we need at most M-1 candidates above us
            if (rank < M) {
                result[candidates[pos].idx] = 0;
                break;
            }

            // Binary search logic: check if this mid is sufficient
            // We want to ensure that even after giving others as much as possible,
            // candidate i can still be in top M

            int l = max(0, N - M);
            if (pos >= l) l--;

            int r = lower_bound(candidates.begin() + l, candidates.end(), Candidate{target, -1}, [](const Candidate& a, const Candidate& b) {
                return a.votes < b.votes;
            }) - candidates.begin();

            if (r <= l) {
                // candidate already in top M
                result[candidates[pos].idx] = 0;
                break;
            }

            // Calculate required extra votes
            ll required = (r - l) * (target + 1) - (prefix_sum[r] - prefix_sum[l]);
            if (pos > l) required -= (target + 1);

            if (required <= K - mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (result[candidates[pos].idx] == 0) continue;

        // After binary search, check feasibility
        ll test_target = candidates[pos].votes + high;
        int left = 0, right = N;
        while (left < right) {
            int m = (left + right) / 2;
            if (candidates[m].votes > test_target)
                right = m;
            else
                left = m + 1;
        }

        int rank = N - left;
        if (rank < M) {
            result[candidates[pos].idx] = 0;
        } else {
            result[candidates[pos].idx] = high + 1;
            if (high + 1 > K) {
                result[candidates[pos].idx] = -1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}