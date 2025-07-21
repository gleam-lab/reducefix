#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    cin >> A;

    // Create a vector of pairs of current votes and index
    vector<pair<long long, int>> votes(N);
    for (int i = 0; i < N; ++i) {
        votes[i] = {A[i], i};
    }

    // Sort by current votes in descending order
    sort(votes.rbegin(), votes.rend());

    // We need to find the maximum votes a candidate can get to ensure victory
    long long max_votes = 0;
    long long count_more_votes = 0;
    for (auto [v, idx] : votes) {
        if (count_more_votes >= M - 1) break;
        count_more_votes++;
        max_votes = v;
    }

    // Calculate votes needed for each candidate
    vector<long long> res(N);
    long long remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);
    for (int i = 0; i < N; ++i) {
        long long votes_needed = max_votes - A[i] + 1;
        if (votes_needed <= remaining_votes) {
            res[i] = votes_needed;
        } else {
            res[i] = -1;
        }
    }

    // Output results
    for (long long vote : res) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}