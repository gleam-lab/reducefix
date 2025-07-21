#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Sort candidates based on votes, then reverse the list
sort(votes.begin(), votes.end(), greater<int>());
reverse(votes.begin(), votes.end());

// Calculate the minimum votes required to guarantee victory
int min_votes_needed = 0;
for (int i = 0; i < min(M, n); ++i) {
    min_votes_needed += votes[i];
}

// Determine the additional votes needed for each candidate
vector<int> additional_votes_needed(n);
for (int i = 0; i < n; ++i) {
    if (votes[i] >= min_votes_needed - (i + 1)) {
        // Candidate i already has enough votes to guarantee victory
        additional_votes_needed[i] = 0;
    } else if (min_votes_needed - (i + 1) > K - sum_votes) {
        // Candidate i cannot guarantee victory even with all remaining votes
        additional_votes_needed[i] = -1;
    } else {
        // Calculate the additional votes needed for Candidate i
        additional_votes_needed[i] = min_votes_needed - (i + 1) - votes[i];
    }
}

// Output the results
for (int i = 0; i < n; ++i) {
    cout << additional_votes_needed[i] << " ";
}