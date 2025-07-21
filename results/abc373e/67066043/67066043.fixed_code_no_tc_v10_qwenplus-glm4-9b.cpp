#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Candidate {
    int id;
    long long votes;
};

struct WinnerCandidate {
    long long votes;
    int requiredMinVotes;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> A(n);
    long long totalVotes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        totalVotes += A[i];
    }

    // Create a vector of candidates
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i].id = i + 1;
        candidates[i].votes = A[i];
    }

    // Sort candidates by votes
    sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
        return a.votes > b.votes;
    });

    // Create a vector to store the minimum votes required for the remaining candidates to become winners
    vector<WinnerCandidate> winners;
    long long sumVotes = 0;
    for (int i = 0; i < n; ++i) {
        sumVotes += candidates[i].votes;
        if (i >= m - 1) { // Only consider the top m-1 candidates to become winners
            winners.emplace_back(candidates[i].votes, k - sumVotes + 1);
        }
    }

    // Sort winners by votes to find the missing votes to secure the minimum votes for the last winner
    sort(winners.begin(), winners.end(), [](const WinnerCandidate &a, const WinnerCandidate &b) {
        return a.votes > b.votes;
    });

    // Check if the last winner can maintain the minimum votes
    long long remainingVotes = k - totalVotes;
    if (winners.front().votes + remainingVotes < winners.front().requiredMinVotes) {
        // If not, output -1 for all
        for (int i = 0; i < n; ++i) {
            cout << -1 << ' ';
        }
    } else {
        // Otherwise, compute the additional votes needed for each candidate
        vector<long long> additionalVotes(n);
        long long votesNeeded = winners.front().requiredMinVotes - winners.front().votes;
        for (int i = 0; i < n; ++i) {
            if (candidates[i].votes + votesNeeded >= winners.front().requiredMinVotes) {
                additionalVotes[candidates[i].id - 1] = votesNeeded;
            } else {
                additionalVotes[candidates[i].id - 1] = 0; // Already guaranteed to be a winner
            }
        }
        for (long long vote : additionalVotes) {
            cout << vote << ' ';
        }
    }

    return 0;
}