#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes > b.votes;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i + 1;
    }

    sort(candidates.begin(), candidates.end(), compare);

    // Calculate prefix sums of votes
    vector<long long> prefix_sums(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sums[i + 1] = prefix_sums[i] + candidates[i].votes;
    }

    vector<long long> results(N, 0);
    for (int i = 0; i < N; ++i) {
        long long needed_votes = 0;
        int remaining_candidates = N - i - 1;

        if (remaining_candidates >= M) {
            continue;
        }

        long long total_remaining_votes = K - prefix_sums[i];
        long long max_votes_for_others = prefix_sums[N] - prefix_sums[i];

        if (max_votes_for_others <= total_remaining_votes) {
            needed_votes = 0;
        } else {
            long long min_required_votes = (max_votes_for_others - total_remaining_votes + remaining_candidates - 1) / remaining_candidates;
            needed_votes = min_required_votes - (candidates[i].votes + 1);
        }

        if (needed_votes < 0) {
            needed_votes = 0;
        }

        results[candidates[i].index - 1] = needed_votes;
    }

    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}