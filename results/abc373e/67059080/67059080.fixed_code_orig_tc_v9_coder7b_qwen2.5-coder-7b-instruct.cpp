#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Candidate {
    ll votes;
    int index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i + 1;
    }

    sort(candidates.begin(), candidates.end());

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    K -= prefix_sum[N];
    if (K < 0) {
        for (int i = 0; i < N; ++i) {
            cout << 0 << " ";
        }
        return 0;
    }

    vector<int> results(N);
    for (int i = 0; i < N; ++i) {
        ll needed_votes = candidates[M - 1].votes + 1 - candidates[i].votes;
        if (needed_votes > K) {
            results[i] = -1;
        } else {
            results[i] = needed_votes;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }

    return 0;
}