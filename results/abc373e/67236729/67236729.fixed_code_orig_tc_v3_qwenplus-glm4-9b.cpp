#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    long long total_votes = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_votes += A[i];
    }

    // Sort candidates by votes received
    sort(A.begin(), A.end());

    vector<long long> min_votes_needed(N, -1);
    long long remaining_votes = K - total_votes;

    // Check each candidate
    for (int i = 0; i < N; ++i) {
        if (i + 1 >= M) { // If the current candidate's rank is greater than or equal to M, they can't win
            min_votes_needed[i] = -1;
        } else {
            // Calculate the minimum additional votes needed to guarantee victory
            long long votes_needed = M - i - 1;
            long long remaining_votes_needed = votes_needed * A.back() - A[i];
            if (remaining_votes >= remaining_votes_needed) {
                min_votes_needed[i] = remaining_votes_needed;
            } else {
                min_votes_needed[i] = -1; // Not enough votes to guarantee victory
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << min_votes_needed[i] << " ";
    }
    cout << endl;

    return 0;
}