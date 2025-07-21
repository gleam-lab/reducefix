#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int idx;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> result(N, -1);

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i].votes = A[i];
        candidates[i].idx = i;
    }

    sort(candidates.begin(), candidates.end(), compare);

    // Prefix sum array of sorted candidate votes
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    for (int i = 0; i < N; ++i) {
        int pos = i; // position in sorted list

        // Binary search to find minimum X needed for candidate i to guarantee win
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll total_remaining = K - mid;

            if (A[candidates[pos].idx] + mid > candidates[N - M].votes) {
                // Already in top M without needing any more votes
                high = mid;
                continue;
            }

            // Find how many candidates have strictly greater votes than this one after adding mid
            ll threshold = A[candidates[pos].idx] + mid;
            auto it = upper_bound(candidates.begin(), candidates.end(), Candidate{threshold, -1}, [](const Candidate& a, const Candidate& b) {
                return a.votes < b.votes;
            });
            int rank = N - (it - candidates.begin());

            if (rank < M) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // After binary search, check if it's possible
        if (low <= K) {
            result[candidates[pos].idx] = low;
        } else {
            result[candidates[pos].idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}