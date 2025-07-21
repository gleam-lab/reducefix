#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Compare {
    bool operator()(pii &p1, pii &p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
};

long long solve(int n, int k, vector<int>& a, vector<int>& b) {
    vector<pii> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {a[i], b[i]};
    }

    sort(pairs.begin(), pairs.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum_b = 0;
    for (int i = 0; i < k - 1; ++i) {
        pq.push(pairs[i].second);
        sum_b += pairs[i].second;
    }

    long long result = LLONG_MAX;
    for (int i = k - 1; i < n; ++i) {
        result = min(result, static_cast<long long>(pairs[i].first) * (sum_b + pairs[i].second));
        if (!pq.empty()) {
            sum_b += pairs[i].second - pq.top();
            pq.pop();
            pq.push(pairs[i].second);
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        cout << solve(n, k, a, b) << endl;
    }

    return 0;
}