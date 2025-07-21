#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Sort the candidates by their votes received
    vector<pair<long long, int>> votes(A.begin(), A.end());
    sort(votes.begin(), votes.end());

    vector<int> votes_needed(N + 1, 0);

    // Calculate the votes needed for each candidate to ensure victory
    for (int i = 0; i < N; ++i) {
        if (i >= M - 1) {
            // Candidate i needs to be at least M-th
            long long required_votes = votes[M - 1].first - votes[i].first;
            if (required_votes > K - A[i]) {
                // Not enough votes to guarantee victory
                votes_needed[i + 1] = -1;
            } else {
                // Calculate additional votes needed
                votes_needed[i + 1] = required_votes - A[i];
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}