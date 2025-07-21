#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    long long votes;
    int idx;
} Candidate;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].idx = i;
    }

    // Sort candidates by votes received in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
        return a.votes > b.votes;
    });

    vector<long long> votes_needed(n);
    long long total_votes = 0;
    for (int i = 0; i < n; ++i) {
        votes_needed[i] = -1;
        total_votes += candidates[i].votes;
    }

    // Only consider top m candidates for victory
    for (int i = 0; i < m; ++i) {
        if (votes_needed[i] == -1) {
            long long remaining_votes = k - total_votes;
            long long votes_to_win = candidates[i].votes + 1 - candidates[i + 1].votes;
            if (remaining_votes >= votes_to_win) {
                votes_needed[i] = votes_to_win - remaining_votes;
            } else {
                votes_needed[i] = 0;
            }
        }
    }

    // Output the minimum votes needed for each candidate
    for (int i = 0; i < n; ++i) {
        if (votes_needed[i] == -1) {
            cout << "-1 ";
        } else {
            cout << votes_needed[i] << " ";
        }
    }
    cout << endl;

    return 0;
}