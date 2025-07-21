#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> queries(q);
    for(int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        queries[i] = {x, k};
    }

    sort(a.begin(), a.end());

    for(auto& query : queries) {
        int x = query[0], k = query[1];
        auto it = lower_bound(a.begin(), a.end(), x);
        int left_count = it - a.begin();

        int dist_left = left_count ? abs(x - a[left_count - 1]) : INT_MAX;
        int dist_right = (left_count == n) ? INT_MAX : abs(x - a[left_count]);

        int result = min(dist_left, dist_right);
        cout << result << '\n';
    }

    return 0;
}