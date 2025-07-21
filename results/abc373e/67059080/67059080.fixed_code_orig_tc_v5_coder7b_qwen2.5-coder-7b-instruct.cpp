#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Candidate {
    int id;
    ll votes;
};

bool operator<(const Candidate &a, const Candidate &b) {
    return a.votes > b.votes || (a.votes == b.votes && a.id < b.id);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].id = i + 1;
    }

    sort(candidates.begin(), candidates.end());

    vector<ll> min_votes(N, -1);

    priority_queue<pair<ll, int>> pq;
    for (int i = 0; i < N; ++i) {
        pq.push({candidates[i].votes, i});
    }

    for (int i = 0; i < N; ++i) {
        while (!pq.empty() && pq.top().second != i) {
            pq.pop();
        }

        if (pq.empty()) break;

        ll votes_needed = pq.top().first - candidates[i].votes + 1;
        if (votes_needed > K) {
            min_votes[i] = -1;
            continue;
        }

        min_votes[i] = votes_needed;
        pq.pop();

        if (M > 1) {
            pq.push({candidates[i].votes + min_votes[i], i});
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << min_votes[i] << " ";
    }

    return 0;
}