#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    int votes;
    int lead;
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].lead = candidates[i].votes;
    }

    // Sort candidates by votes in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
        return a.votes > b.votes;
    });

    // Calculate the lead for each candidate
    for (int i = 0; i < N; ++i) {
        if (i < N - 1) {
            candidates[i].lead = candidates[i].votes - candidates[i + 1].votes + 1;
        }
    }

    // Calculate additional votes needed for each candidate
    vector<int> additionalVotes(N, -1);
    for (int i = 0; i < N; ++i) {
        if (i + 1 < N && candidates[i].lead >= M) {
            additionalVotes[i] = 0; // Already guaranteed to win
        } else if (i + 1 < N && candidates[i].lead < M) {
            int requiredVotes = 0;
            for (int j = i; j < N && candidates[j].lead < candidates[i].lead + M; ++j) {
                requiredVotes += candidates[j].votes - candidates[j].lead;
            }
            if (K - (accumulate(candidates.begin(), candidates.end(), 0)) - requiredVotes >= 0) {
                additionalVotes[i] = candidates[i].lead + M - candidates[i].votes;
            } else {
                additionalVotes[i] = -1;
            }
        }
    }

    // Output the result
    for (int i = 0; i < N; ++i) {
        cout << additionalVotes[i] << " ";
    }
    cout << endl;

    return 0;
}