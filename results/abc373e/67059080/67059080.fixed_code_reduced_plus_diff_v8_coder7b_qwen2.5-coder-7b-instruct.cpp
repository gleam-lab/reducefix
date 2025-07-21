#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Candidate {
    ll votes;
    int index;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;

    vector<Candidate> candidates(N + 5);

    for (int i = 1; i <= N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    sort(candidates.begin() + 1, candidates.end(), compare);

    vector<ll> prefix(N + 5);
    prefix[0] = 0LL;
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + candidates[i].votes;
    }

    K -= prefix[N];

    vector<ll> result(N + 5, -1);

    for (int i = 1; i <= N; ++i) {
        if (candidates[i].votes + K >= prefix[N]) {
            result[candidates[i].index] = 0;
            continue;
        }

        int left = 0, right = K;
        while (left < right) {
            int mid = (left + right) / 2;
            ll need = candidates[i].votes + mid + 1;
            int cnt = lower_bound(candidates.begin() + i + 1, candidates.end(), (Candidate){need, 0}) - candidates.begin();

            if (cnt >= M) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        result[candidates[i].index] = left - (candidates[i].votes + K);
    }

    for (int i = 1; i <= N; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}