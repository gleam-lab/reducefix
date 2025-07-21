#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    long long a; // Total votes received so far by the candidate
    int n;       // Total votes that can be cast
    int rank;    // Rank of the candidate in the sorted result
} Candidate;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    long long total_votes = 0; // Total votes received so far

    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].a;
        total_votes += candidates[i].a;
        candidates[i].n = K - total_votes;
        candidates[i].rank = 0;
    }

    // Sort candidates by the votes needed to secure a victory
    sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
        return a.n < b.n;
    });

    vector<long long> votes_needed(N);
    long long remaining_votes = K - total_votes;

    // Calculate the minimum votes needed for each candidate to secure a victory
    for (int i = 0; i < N; ++i) {
        if (i < M) {
            // If there are less than M candidates, they are all guaranteed to win
            votes_needed[i] = 0;
        } else {
            // Calculate the votes needed for the current candidate to surpass the Mth candidate
            int current_rank = i - M;
            int votes_to_surpass = candidates[current_rank].a; // Votes of the Mth candidate
            votes_needed[i] = votes_to_surpass - candidates[i].a;
            if (votes_needed[i] > remaining_votes) {
                votes_needed[i] = -1; // Cannot secure victory
            } else {
                remaining_votes -= votes_needed[i];
            }
        }
    }

    // Output the votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        cout << votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}