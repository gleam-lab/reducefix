#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(q);
    vector<int> k(q);
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    sort(a.begin(), a.end());

    auto find_kth_closest = [&](int b_j) -> int {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (abs(a[m] - b_j) >= abs(a[l] - b_j)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = max(l - k, 0); i <= min(l + k, n - 1); ++i) {
            int dist = abs(a[i] - b_j);
            pq.push({dist, a[i]});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top().first;
    };

    for (int i = 0; i < q; ++i) {
        cout << find_kth_closest(b[i]) << '\n';
    }

    return 0;
}