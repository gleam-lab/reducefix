#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Candidate {
    int id;
    ll votes;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes > b.votes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for(int i = 0; i < N; i++) {
        cin >> candidates[i].votes;
        candidates[i].id = i + 1;
    }

    sort(candidates.begin(), candidates.end(), compare);

    ll totalVotes = accumulate(candidates.begin(), candidates.end(), 0LL, [](ll sum, const Candidate& c){return sum + c.votes;});

    if(totalVotes == K) {
        cout << string(N, '0') << '\n';
        return 0;
    }

    if(K > totalVotes) {
        cout << string(N, '-1') << '\n';
        return 0;
    }

    ll requiredVotes = K - candidates[0].votes;
    int candidatesToConsider = min(M, N - 1);

    vector<int> results(N, -1);
    for(int i = 0; i < candidatesToConsider; i++) {
        ll currentTotal = totalVotes;
        for(int j = 0; j <= i; j++) {
            currentTotal += candidates[j].votes;
        }

        if(currentTotal >= K) {
            results[candidates[i].id - 1] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        if(results[i] == -1 && candidates[i].votes > K) {
            results[i] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        if(results[i] == -1) {
            results[i] = requiredVotes - candidates[i].votes + 1;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << results[i] << " ";
    }

    return 0;
}