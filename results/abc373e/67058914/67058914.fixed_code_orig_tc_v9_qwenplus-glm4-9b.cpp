#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;
ll votes[200100];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    // Sort candidates by votes
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (votes[i] < votes[j]) {
                swap(votes[i], votes[j]);
            }
        }
    }

    // Calculate required votes for each candidate
    for (int i = 0; i < N; ++i) {
        ll required = votes[N - M] - 1; // Votes of the M-th candidate less one
        if (votes[i] + K - (i + 1) * required < required) {
            required = votes[i] + K - (i + 1) * required;
        }
        votes[i] = required - votes[i] + 1;
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << votes[i] << ' ';
    }
    cout << '\n';
    return 0;
}