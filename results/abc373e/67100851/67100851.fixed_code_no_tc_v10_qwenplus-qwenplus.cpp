#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

bool compareByVotes(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    ll total_votes = 0;

    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        total_votes += candidates[i].votes;
        candidates[i].index = i;
    }

    ll remaining_votes = K - total_votes;
    if (remaining_votes < 0) {
        for (int i = 0; i < N; ++i) cout << "-1 ";
        cout << endl;
        return 0;
    }

    // Sort candidates by current votes
    sort(candidates.begin(), candidates.end(), compareByVotes);

    // Prefix sum of current votes
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    vector<ll> result(N);

    // For binary search
    vector<ll> additional_votes(N, -1);

    // Process each candidate
    for (int i = 0; i < N; ++i) {
        int pos = i; // position in sorted array

        // Binary search for minimal X
        ll low = 0;
        ll high = remaining_votes;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote_count = candidates[i].votes + mid;

            // Find how many candidates have votes > new_vote_count
            // We need to ensure that at most M-1 candidates can have more votes than this one
            // So we find the smallest index where votes > new_vote_count
            int idx = upper_bound(
                candidates.begin(), candidates.end(), Candidate{new_vote_count, -1},
                [](const Candidate &a, const Candidate &b) { return a.votes < b.votes; })
                - candidates.begin();

            // We cannot count the candidate themselves if they are in the top M
            int max_allowed_above = M - 1;
            int current_above = N - idx;

            if (current_above > max_allowed_above) {
                low = mid + 1;
                continue;
            }

            // Calculate minimum extra votes needed to push up others
            int target_idx = N - max_allowed_above;
            if (pos >= target_idx) target_idx--;

            if (idx <= target_idx) {
                ll required = (target_idx) * (new_vote_count + 1) - (prefix_sum[target_idx]);
                if (required > remaining_votes - mid) {
                    low = mid + 1;
                    continue;
                }
            }

            answer = mid;
            high = mid - 1;
        }

        additional_votes[i] = answer;
    }

    // Reorder results back to original candidate order
    vector<ll> final_result(N);
    for (int i = 0; i < N; ++i) {
        final_result[candidates[i].index] = additional_votes[i];
    }

    for (int i = 0; i < N; ++i) {
        if (final_result[i] == -1) cout << "-1 ";
        else cout << final_result[i] << " ";
    }
    cout << endl;

    return 0;
}