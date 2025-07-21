#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Candidate {
    ll votes;
    int index;
};

bool cmp(const Candidate& a, const Candidate& b) {
    return a.votes < b.votes;
}

int main() {
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i + 1;
    }

    sort(candidates.begin(), candidates.end(), cmp);

    vector<ll> prefixSum(N + 1);
    prefixSum[0] = 0;
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes;
    }

    K -= prefixSum.back();

    vector<ll> results(N, -1);
    for (int i = 0; i < N; ++i) {
        if (candidates[i].votes + K >= prefixSum[N] - prefixSum[i]) {
            results[i] = 0;
        } else {
            int targetVotes = candidates[i].votes + K + 1;
            auto it = upper_bound(candidates.begin() + i + 1, candidates.end(), (Candidate){targetVotes, 0}, cmp);
            if (it == candidates.end()) {
                results[i] = -1;
            } else {
                int countExceeding = N - (it - candidates.begin());
                if (countExceeding < M) {
                    results[i] = 0;
                } else {
                    results[i] = targetVotes - candidates[i].votes - 1;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}