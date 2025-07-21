#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Pair candidates with their current votes and sort by votes descending
    vector<pair<long long, int>> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {A[i], i};
    }
    sort(candidates.rbegin(), candidates.rend());

    // Calculate the number of votes each candidate needs to guarantee victory
    vector<long long> needed_votes(N, -1);
    long long total_votes_so_far = 0;
    for (int i = 0; i < M; ++i) {
        long long votes_needed = M * candidates[i].first - total_votes_so_far;
        if (votes_needed <= K - total_votes_so_far) {
            needed_votes[candidates[i].second] = votes_needed;
        } else {
            needed_votes[candidates[i].second] = -1;
        }
        total_votes_so_far += candidates[i].first;
    }

    // Output the results
    for (long long vote : needed_votes) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}