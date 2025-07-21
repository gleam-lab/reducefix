#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    long long votes;
    int index;
} Candidate;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    long long total_votes = 0;
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
        total_votes += candidates[i].votes;
    }

    sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
        return a.votes > b.votes;
    });

    vector<long long> required_votes(N, -1);
    vector<long long> remaining_votes(K);
    for (int i = 0; i < N; ++i) {
        long long votes_needed = 0;
        for (int j = 0; j < N; ++j) {
            if (j < i) {
                votes_needed += candidates[i].votes - candidates[j].votes;
            } else if (j == i) {
                votes_needed += M;
            } else {
                votes_needed += candidates[i].votes - candidates[j].votes + 1;
            }
        }
        required_votes[i] = votes_needed;
        for (int j = 0; j < votes_needed; ++j) {
            remaining_votes[j] = 1;
        }
    }

    long long max_votes = 0;
    for (int i = 0; i < N; ++i) {
        if (required_votes[i] != -1) {
            for (int j = 0; j < remaining_votes.size(); ++j) {
                max_votes = max(max_votes, candidates[i].votes + j);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (candidates[i].votes == max_votes) {
            cout << 0 << " ";
        } else {
            cout << -1 << " ";
        }
    }

    cout << endl;
    return 0;
}