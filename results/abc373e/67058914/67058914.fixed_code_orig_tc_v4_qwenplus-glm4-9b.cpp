#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector long long votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    sort(votes.begin(), votes.end(), greater<long long>());

    vector long long additional_votes(N);
    for (int i = 0; i < N; ++i) {
        int rank = i + 1;
        int min_rank_to_surpass = max(rank, M - 1);
        long long votes_needed = votes[i] + (min_rank_to_surpass - rank);
        additional_votes[i] = votes_needed;
    }

    for (int i = 0; i < N; ++i) {
        cout << additional_votes[i] << ' ';
    }
    cout << endl;

    return 0;
}