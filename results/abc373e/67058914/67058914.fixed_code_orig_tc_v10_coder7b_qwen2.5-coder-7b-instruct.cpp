#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Candidate {
    ll votes;
    int index;
};

bool cmp(const Candidate &a, const Candidate &b) {
    return a.votes > b.votes;
}

int main() {
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i + 1;
    }

    sort(candidates.begin(), candidates.end(), cmp);

    vector<ll> prefix_sum(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + candidates[i - 1].votes;
    }

    K -= prefix_sum[N];
    if (K < 0) {
        K = 0;
    }

    vector<int> result(N, 0);
    for (int i = 0; i < N; ++i) {
        ll required_votes = candidates[i].votes + 1;
        int remaining_candidates = N - i - 1;
        if (remaining_candidates >= M) {
            result[candidates[i].index - 1] = -1;
            continue;
        }

        ll total_remaining_votes = K - (prefix_sum[N] - prefix_sum[i + 1]);
        ll min_additional_votes = ceil((double)(total_remaining_votes / (M - remaining_candidates)));

        result[candidates[i].index - 1] = max(0LL, required_votes - candidates[i].votes);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}