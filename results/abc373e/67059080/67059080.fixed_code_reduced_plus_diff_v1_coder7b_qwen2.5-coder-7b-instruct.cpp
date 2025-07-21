#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Candidate {
    ll votes;
    int index;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    sort(candidates.rbegin(), candidates.rend());

    vector<ll> prefix_sum(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + candidates[i - 1].votes;
    }

    K -= prefix_sum[N];

    vector<ll> results(N, -1);
    for (int i = 0; i < N; ++i) {
        if (candidates[i].votes + K < candidates[i].votes + 1 + (M - 1)) {
            results[candidates[i].index] = candidates[i].votes + 1 + (M - 1) - candidates[i].votes;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (results[i] == -1) {
            results[i] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }

    return 0;
}