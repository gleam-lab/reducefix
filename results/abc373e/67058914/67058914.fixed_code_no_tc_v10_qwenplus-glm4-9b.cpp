#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll sum_votes = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_votes += A[i];
    }

    vector<pair<ll, int>> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {A[i], i + 1};
    }

    // Sort candidates by number of votes, descending
    sort(candidates.rbegin(), candidates.rend());

    vector<ll> remaining_votes(K - sum_votes);
    for (int i = 0; i < remaining_votes.size(); ++i) {
        remaining_votes[i] = (i < M - 1) ? 1 : 0;
    }

    // Sort remaining votes to have the smallest votes first
    sort(remaining_votes.begin(), remaining_votes.end());

    vector<ll> result(N, -1);
    ll required_votes = 0;
    for (int i = 0; i < N; ++i) {
        ll votes_needed = candidates[i].first + (M - 1) * remaining_votes[i];
        if (votes_needed <= candidates[i].first) {
            result[candidates[i].second - 1] = 0;
        } else {
            required_votes += votes_needed - candidates[i].first;
            if (required_votes > K) {
                result[candidates[i].second - 1] = -1;
            } else {
                result[candidates[i].second - 1] = votes_needed - candidates[i].first;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}