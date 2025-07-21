#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (ll i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    vector<ll> result(N, -1);

    // We'll sort the candidates by current votes
    sort(candidates.begin(), candidates.end(), [](const Candidate &a, const Candidate &b) {
        return a.votes < b.votes;
    });

    // Prefix sum array to help with efficient range queries
    vector<ll> prefix_sum(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    for (ll i = 0; i < N; ++i) {
        ll left = 0, right = K;
        ll ans = -1;

        while (left <= right) {
            ll mid = (left + right) / 2;
            ll idx = lower_bound(candidates.begin(), candidates.end(), Candidate{mid + candidates[i].votes, -1},
                                 [&](const Candidate &a, const Candidate &b) {
                                     if (a.votes == b.votes) return a.index < b.index;
                                     return a.votes < b.votes;
                                 }) - candidates.begin();

            // We need to find how many candidates have more than this candidate after adding mid votes
            ll stronger = N - idx;

            // If we're in top M-1 candidates even in worst case, we win
            if (stronger < M) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // If no such value found, it's impossible to win
        if (ans == -1 && (K >= 0)) {
            // Check if already in winning position
            ll idx = lower_bound(candidates.begin(), candidates.end(), Candidate{candidates[i].votes, -1},
                                 [&](const Candidate &a, const Candidate &b) {
                                     if (a.votes == b.votes) return a.index < b.index;
                                     return a.votes < b.votes;
                                 }) - candidates.begin();
            ll stronger = N - idx;
            if (stronger < M) {
                result[candidates[i].index] = 0;
            } else {
                result[candidates[i].index] = -1;
            }
        } else {
            result[candidates[i].index] = ans;
        }
    }

    for (ll i = 0; i < N; ++i) {
        cout << result[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}