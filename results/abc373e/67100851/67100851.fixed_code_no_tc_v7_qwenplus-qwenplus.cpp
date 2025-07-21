#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
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

    vector<Candidate> candidates(N);
    ll total = 0;

    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        total += candidates[i].votes;
        candidates[i].index = i;
    }

    K -= total; // Remaining votes

    vector<ll> result(N);
    vector<ll> prefix_sum(N + 1, 0);

    // Sort candidates by current votes
    sort(candidates.begin(), candidates.end(), compare);

    // Precompute prefix sums
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    for (int i = 0; i < N; ++i) {
        int pos = i; // Position in sorted array

        // Binary search for the smallest X such that candidate i is guaranteed to be elected
        ll left = 0;
        ll right = K;
        ll answer = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll target_votes = candidates[i].votes + mid;

            // Find how many candidates have votes > target_votes
            // We use binary search to find first candidate with votes >= target_votes
            int idx = upper_bound(candidates.begin(), candidates.end(), Candidate{target_votes, -1}, compare) - candidates.begin();

            // We need at most M-1 candidates to have more votes than this one
            // So we check if at least (N - (M - 1)) candidates have votes <= target_votes
            // That means this candidate is among top M
            if (N - idx >= M) {
                answer = mid;
                right = mid - 1;
            } else {
                // Not enough candidates can be below us -- not safe
                left = mid + 1;
            }
        }

        result[candidates[i].index] = (answer == -1 ? -1 : answer);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}