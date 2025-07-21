#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Sort candidates by votes received
    vector<pair<long long, int>> candidates(N + 1);
    for (int i = 1; i <= N; ++i) {
        candidates[i] = {A[i], i};
    }
    sort(candidates.begin(), candidates.end());

    // Pre-compute the votes needed to ensure victory
    vector<long long> votes_to_win(N + 1);
    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += A[candidates[i].second];
        votes_to_win[i] = sum + M - 1;
    }

    // Calculate the minimum additional votes required for each candidate
    vector<int> additional_votes(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int current_votes = A[candidates[i].second];
        long long votes_needed = votes_to_win[i];
        int idx = upper_bound(candidates.begin(), candidates.end(), {current_votes + 1, 0}) - candidates.begin();
        long long required_votes = votes_needed - (sum - (sum - votes_to_win[idx - 1]));
        additional_votes[candidates[i].second] = required_votes - current_votes;
    }

    // Output the result
    for (int i = 1; i <= N; ++i) {
        cout << additional_votes[i] << ' ';
    }
    cout << '\n';

    return 0;
}