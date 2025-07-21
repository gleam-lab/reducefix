#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const long long INFL = 2e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    priority_queue<pair<int, int>> pq_a;
    priority_queue<int> pq_b;
    
    for(int i = 0; i < n; ++i) {
        pq_a.push({a[i], b[i]});
        pq_b.push(b[i]);
    }

    int max_a = 0, sum_b = 0;
    for(int i = 0; i < k; ++i) {
        max_a = max(max_a, pq_a.top().first);
        sum_b += pq_a.top().second;
        pq_a.pop();
    }

    long long res = static_cast<long long>(max_a) * sum_b;

    while(!pq_a.empty()) {
        int new_a = pq_a.top().first;
        int new_b = pq_a.top().second;
        pq_a.pop();

        sum_b += new_b - pq_b.top();
        pq_b.pop();
        pq_b.push(new_b);

        res = min(res, static_cast<long long>(new_a) * sum_b);
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}