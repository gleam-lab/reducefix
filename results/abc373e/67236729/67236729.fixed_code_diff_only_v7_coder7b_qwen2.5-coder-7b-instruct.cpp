#include <bits/stdc++.h>

using namespace std;

long long calculate_additional_votes(long long votes, int rank, int M, long long remaining_votes) {
    if (rank <= M) {
        return 0;
    }

    long long needed_votes = (M - (rank - 1)) * (remaining_votes / (M - 1)) + (votes + remaining_votes % (M - 1) >= votes + remaining_votes / (M - 1));

    return max(needed_votes - votes, 0LL);
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
        K -= votes[i];
    }

    sort(votes.begin(), votes.end());

    for (int i = 0; i < N; ++i) {
        long long additional_votes = calculate_additional_votes(votes[i], i + 1, M, K);
        cout << additional_votes << " ";
    }

    cout << endl;
    return 0;
}