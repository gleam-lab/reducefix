#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Candidate {
    int index;
    ll votes;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });

    vector<ll> prefix_sum(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + candidates[i - 1].votes;
    }

    vector<ll> results(N, 0);

    for (int i = 0; i < N; ++i) {
        ll total_votes_needed = 0;
        int count_larger = 0;

        for (int j = 0; j < N; ++j) {
            if (j != i && candidates[j].votes > candidates[i].votes) {
                total_votes_needed += candidates[j].votes + 1;
                count_larger++;
            }
        }

        if (count_larger < M) {
            results[candidates[i].index] = total_votes_needed - prefix_sum[count_larger];
        } else {
            results[candidates[i].index] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}