#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

struct cmp {
    bool operator()(const pll &a, const pll &b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
};

vector<ll> get_min_subset(const vector<ll> &A, const vector<ll> &B, int K) {
    int n = A.size();
    priority_queue<pll, vector<pll>, cmp> pq;

    for (int i = 0; i < n; ++i) {
        pq.push({A[i], B[i]});
    }

    vector<ll> selected(K);
    while (!pq.empty() && K > 0) {
        auto [a, b] = pq.top(); pq.pop();
        selected[--K] = b;
    }

    return selected;
}

ll calculate_result(const vector<ll> &selected, const vector<ll> &A) {
    if (selected.empty()) return 0;
    ll max_val = *max_element(selected.begin(), selected.end());
    ll sum = accumulate(selected.begin(), selected.end(), 0LL);
    return max_val * sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];

        vector<ll> selected = get_min_subset(A, B, k);
        ll result = calculate_result(selected, A);
        cout << result << "\n";
    }

    return 0;
}