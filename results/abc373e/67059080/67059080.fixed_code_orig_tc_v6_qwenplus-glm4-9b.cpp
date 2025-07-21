#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Candidate {
    long long votes;
    int id;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes > b.votes; // To sort in descending order of votes
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].id = i;
    }

    sort(candidates.begin(), candidates.end(), compare);

    vector<long long> prefix(n);
    prefix[0] = candidates[0].votes;
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + candidates[i].votes;
    }

    vector<long long> required_votes(n, -1); // Initialize required votes as -1 (indicating not calculated yet)

    for (int i = 0; i < n; ++i) {
        long long needed_votes = 0;
        long long current_votes = candidates[i].votes + prefix[n - 1] - prefix[i];

        // Binary search to find the minimum votes needed to ensure i is in the top m
        int low = 0, high = k - (prefix[n - 1] - prefix[i]);
        while (low < high) {
            int mid = (low + high + 1) / 2;
            long long remaining_votes = k - (prefix[n - 1] - prefix[i]) - mid;

            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (j <= i) {
                    count += min(mid, candidates[j].votes);
                } else {
                    count += candidates[j].votes;
                }
            }

            if (count <= remaining_votes) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        needed_votes = low;

        if (i < m - 1) { // If not already in the top m, calculate the additional votes needed
            long long votes_needed = m * candidates[i + 1].votes - (prefix[n - 1] - prefix[i + 1]);
            needed_votes = max(needed_votes, votes_needed);
        }

        required_votes[candidates[i].id] = needed_votes;
    }

    for (int i = 0; i < n; ++i) {
        cout << required_votes[i] << " ";
    }
    cout << endl;

    return 0;
}