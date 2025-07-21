#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Candidate {
    long long votes;
    long long remaining_votes;
    int index;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.remaining_votes < b.remaining_votes;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    vector<Candidate> candidates(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        candidates[i].votes = A[i];
        candidates[i].remaining_votes = M - 1;  // M-1 is the minimum votes needed to guarantee victory
        candidates[i].index = i;
    }

    sort(candidates.begin(), candidates.end(), compare);

    long long total_votes_given = 0;
    for (const auto &candidate : candidates) {
        total_votes_given += candidate.votes;
    }

    long long votes_needed = K - total_votes_given;
    vector<long long> votes_remaining(N);
    fill(votes_remaining.begin(), votes_remaining.end(), votes_needed);

    for (int i = 0; i < N; ++i) {
        if (votes_remaining[i] + candidates[i].votes >= candidates[i].remaining_votes) {
            // This candidate will definitely win or has already won
            continue;
        } else {
            // Binary search to find the minimum votes needed for this candidate
            long long low = 0, high = votes_needed;
            while (low < high) {
                long long mid = (low + high + 1) / 2;
                long long current_votes = candidates[i].votes + mid;
                long long num_candidates_beaten = 0;

                for (int j = i + 1; j < N; ++j) {
                    if (current_votes >= candidates[j].votes) {
                        num_candidates_beaten++;
                    }
                }

                if (num_candidates_beaten < candidates[i].remaining_votes) {
                    high = mid - 1;
                } else {
                    low = mid;
                }
            }
            votes_remaining[i] = low;
        }
    }

    for (const auto &candidate : candidates) {
        cout << votes_remaining[candidate.index] << " ";
    }
    cout << endl;

    return 0;
}