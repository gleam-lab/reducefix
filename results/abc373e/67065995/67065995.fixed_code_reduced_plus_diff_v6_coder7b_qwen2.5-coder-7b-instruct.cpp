#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<long long, int>> sorted_a;
    for (int i = 0; i < n; ++i) {
        sorted_a.emplace_back(a[i], i);
    }
    sort(sorted_a.begin(), sorted_a.end());

    vector<long long> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i].first;
    }

    vector<long long> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int id = sorted_a[i].second;
        long long required_votes = 0;

        if (i + 1 >= m) {
            required_votes = sorted_a[n - 1].first + 1 - sorted_a[i].first;
        } else {
            required_votes = prefix[n] - prefix[i + 1] - (m - 1) * (sorted_a[i].first + 1);
        }

        if (required_votes <= k) {
            ans[id] = required_votes;
        } else {
            ans[id] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}