#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

// Function to check if a candidate can win with at least x more votes
bool canWin(vector<Candidate>& candidates, int m, long long k, int i, long long x) {
    // Sort candidates based on votes
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) { return a.votes < b.votes; });

    // Calculate the total votes needed to surpass m-1 candidates
    long long totalVotesNeeded = 0;
    for (int j = 0; j < min(m - 1, static_cast<int>(candidates.size() - 1)); ++j) {
        totalVotesNeeded += candidates[j].votes + 1;
    }

    // Adjust the votes for the current candidate
    candidates[i].votes += x;

    // Check if the current candidate's votes are enough after sorting again
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) { return a.votes < b.votes; });
    if (candidates[m - 1].votes > candidates[i].votes) {
        return false;
    }

    // Restore the original votes count
    candidates[i].votes -= x;

    return true;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    // Calculate the sum of votes received so far
    long long totalVotesReceived = 0;
    for (const auto& candidate : candidates) {
        totalVotesReceived += candidate.votes;
    }

    // Remaining votes to be counted
    k -= totalVotesReceived;

    // Initialize results array with -1 (default value)
    vector<long long> results(n, -1);

    // Iterate over each candidate to calculate the minimum additional votes needed
    for (int i = 0; i < n; ++i) {
        if (canWin(candidates, m, k, i, 0)) {
            results[i] = 0;
        } else {
            long long low = 0, high = k;
            while (low <= high) {
                long long mid = (low + high) / 2;
                if (canWin(candidates, m, k, i, mid)) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            results[i] = low;
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}