#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Candidate {
    long long votes;
    long long required;
    int id;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes > b.votes;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> votes(n);
    for (long long i = 0; i < n; i++) {
        cin >> votes[i];
    }

    set<long long> sorted_votes(votes.begin(), votes.end());
    sort(votes.begin(), votes.end(), greater<long long>());

    vector<Candidate> candidates;
    for (long long i = 0; i < n; i++) {
        candidates.push_back({votes[i], 0, i + 1});
    }

    // Set the required votes for each candidate to win
    int min_candidates_to_win = n - m;
    for (int i = 0; i < min_candidates_to_win; i++) {
        candidates[i].required = votes[i] + (m - 1) * votes[0] + 1;
    }

    // Update the votes required based on the number of votes left that haven't been distributed
    for (int i = min_candidates_to_win; i < n; i++) {
        candidates[i].required = votes[i] + (m - 1) * votes[0] + 1 - (k - candidates[i].votes);
    }

    // Sort the candidates by votes and then by required votes
    sort(candidates.begin(), candidates.end(), compare);

    // Find the maximum required votes among the top m-1 candidates
    long long max_required_votes = 0;
    for (int i = 0; i < min_candidates_to_win; i++) {
        max_required_votes = max(max_required_votes, candidates[i].required);
    }

    // Set the votes to win for each candidate
    for (int i = 0; i < n; i++) {
        candidates[i].required = max(candidates[i].required, max_required_votes);
    }

    // Output the minimum additional votes needed for each candidate
    for (auto& candidate : candidates) {
        if (candidate.required == LLONG_MAX) {
            cout << -1 << " ";
        } else {
            cout << candidate.required - votes[candidate.id - 1] << " ";
        }
    }
    cout << endl;

    return 0;
}