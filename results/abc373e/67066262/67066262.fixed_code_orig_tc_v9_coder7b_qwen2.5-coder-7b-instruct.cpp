#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> minAdditionalVotes(vector<int>& A, int M, ll K) {
    int n = A.size();
    vector<int> sortedIndices(n);
    iota(sortedIndices.begin(), sortedIndices.end(), 0);
    sort(sortedIndices.begin(), sortedIndices.end(), [&](int i, int j) { return A[i] < A[j]; });

    vector<int> result(n, -1);
    priority_queue<pair<int, int>> pq; // {votes, index}

    for (int i = 0; i < n; ++i) {
        pq.push({A[i], sortedIndices[i]});
    }

    while (!pq.empty()) {
        int votes = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if (idx >= n - M) {
            continue;
        }

        int required = 0;
        for (int j = idx + 1; j < n; ++j) {
            required = max(required, pq.top().first - votes + 1);
            pq.pop();
        }

        result[idx] = required;
        for (int j = idx + 1; j < n; ++j) {
            pq.push({votes + result[idx], sortedIndices[j]});
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> res = minAdditionalVotes(a, m, k);

    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}