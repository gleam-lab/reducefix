#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort candidates by votes received in descending order
    sort(A.begin(), A.end(), greater<long long>());

    // Calculate the minimum votes needed to ensure victory
    for (int i = 0; i < N; ++i) {
        // The candidate with the most votes needs to have more votes than M-1 other candidates
        long long votes_needed = A[i] + (M - 1) * A[0] - A[i];
        if (votes_needed > K - A[i]) { // Check if it's possible to win
            votes_needed = -1; // Not possible to win
        }
        cout << votes_needed << (i < N - 1 ? " " : "");
    }

    return 0;
}