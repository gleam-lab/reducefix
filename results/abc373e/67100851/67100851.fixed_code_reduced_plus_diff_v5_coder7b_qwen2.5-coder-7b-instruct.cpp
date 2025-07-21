#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool can_win(vector<Candidate>& candidates, int M, long long x) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (const auto& c : candidates) {
        pq.push({c.votes + x, c.index});
    }

    vector<bool> eliminated(candidates.size(), false);

    for (int i = 0; i < candidates.size() - M; ++i) {
        auto [votes, idx] = pq.top(); pq.pop();
        if (eliminated[idx]) continue;

        eliminated[idx] = true;
        pq.push({votes + x, idx});
    }

    return pq.top().first <= candidates[candidates.size() - M].votes + x;
}

vector<long long> min_votes_to_win(vector<int>& votes, int M, long long total_votes) {
    int n = votes.size();
    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {votes[i], i};
    }

    sort(candidates.begin(), candidates.end());

    long long left = 0, right = total_votes - accumulate(votes.begin(), votes.end(), 0LL);
    vector<long long> result(n, -1);

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (can_win(candidates, M, mid)) {
            result[candidates[n - M].index] = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (result[i] == -1) result[i] = 0;
    }

    return result;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<int> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    vector<long long> results = min_votes_to_win(votes, M, K);
    
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}