#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Binary search with sorted array to find k-th smallest distance
ll find_kth_distance(const vector<ll>& a_sorted, ll b, int k) {
    // Create array of absolute differences
    vector<ll> diffs;
    for (ll x : a_sorted) {
        diffs.push_back(abs(x - b));
    }

    // Use nth_element to find the k-th smallest in O(N)
    nth_element(diffs.begin(), diffs.begin() + k - 1, diffs.end());
    return diffs[k - 1];
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort A once
    sort(a.begin(), a.end());

    // Process each query
    for (int i = 0; i < q; ++i) {
        ll b;
        int k;
        cin >> b >> k;

        // Find and print the k-th smallest distance
        cout << find_kth_distance(a, b, k) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}