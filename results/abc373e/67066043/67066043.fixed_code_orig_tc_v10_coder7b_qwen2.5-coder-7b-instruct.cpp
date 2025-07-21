#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const long long INF = 1LL << 60;

vector<long long> countVotes(vector<long long>& votes, int M) {
    int n = votes.size();
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + votes[i];
    }

    vector<long long> minVotes(n, -1);

    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({votes[i], i});
    }

    int needed = 0;
    while (!pq.empty() && pq.top().first > needed) {
        auto [v, idx] = pq.top(); pq.pop();
        needed++;
        minVotes[idx] = needed - 1;
        if (needed >= M) break;
    }

    return minVotes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        k -= votes[i];
    }

    vector<long long> result = countVotes(votes, m);

    for (int i = 0; i < n; ++i) {
        if (result[i] != -1) {
            result[i] = max(result[i], k / (n - result[i]));
        }
    }

    for (long long x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}