#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N);
    for (long long &a : A) cin >> a;

    // Sort the votes in descending order
    sort(A.rbegin(), A.rend());

    // Array to store the minimum votes needed for each candidate
    vector<long long> votes_needed(N);

    // Calculate votes needed for the first candidate
    votes_needed[A.size() - 1] = max(0LL, A[A.size() - 1] + M - 1 - A[A.size() - M]);

    // Calculate votes needed for the remaining candidates
    for (int i = 0; i < N - 1; ++i) {
        // If the candidate is already better than the minimum required votes, no extra votes needed
        if (A[i] >= votes_needed[A.size() - 1]) {
            votes_needed[i] = 0;
        } else {
            // Otherwise, calculate the votes needed to match or exceed the minimum required votes
            votes_needed[i] = votes_needed[A.size() - 1] - A[i];
        }
    }

    // Output the result in the order of the original array
    for (long long i : votes_needed) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}