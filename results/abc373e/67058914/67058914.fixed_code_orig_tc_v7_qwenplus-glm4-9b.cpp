#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); // Sort the votes to determine the current order

    vector<ll> additionalVotes(N);
    vector<bool> canWin(N, true);

    ll sumVotes = 0;
    for (int i = 0; i < N; i++) {
        sumVotes += A[i]; // Calculate sum of already counted votes
    }

    for (int i = 0; i < N; i++) {
        if (i >= M - 1) {
            canWin[i] = false; // If candidate i has enough votes to guarantee victory (because there are more top candidates than allowed)
        }
        if (canWin[i]) {
            additionalVotes[i] = M - 1 - i; // Additional votes needed to ensure victory
        }
    }

    for (int i = 0; i < N; i++) {
        if (!canWin[i]) {
            additionalVotes[i] = -1; // Set impossible to win candidates to -1
        }
    }

    for (int i = 0; i < N; i++) {
        if (K - sumVotes < additionalVotes[i]) {
            additionalVotes[i] = -1; // Set to -1 if not enough remaining votes
        }
    }

    for (int i = 0; i < N; i++) {
        cout << additionalVotes[i] << " ";
    }
    cout << endl;

    return 0;
}