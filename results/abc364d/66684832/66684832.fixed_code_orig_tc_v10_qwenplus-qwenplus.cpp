#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

int n, q;
vector<int> a;

// Binary search to find the k-th smallest distance
int query(int b, int k) {
    // Use two pointers to maintain a sliding window of distances around b
    int left = 0, right = 0;
    vector<int> window;

    // Sort all distances from a[i] to b
    vector<int> dists(n);
    for (int i = 0; i < n; ++i)
        dists[i] = abs(a[i] - b);

    // Sort distances to get k-th smallest
    nth_element(dists.begin(), dists.begin() + k - 1, dists.end());
    return dists[k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;

    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << query(b, k) << "\n";
    }

    return 0;
}