#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<int, int>>
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

// Binary search to find the k-th smallest distance from b to elements in a
ll solveQuery(int b, int k, const vll& prefixSums, const vi& a) {
    int n = a.size();
    // We binary search on the possible distance
    ll low = 0, high = 2e14; // Safe upper bound based on input range
    while (low < high) {
        ll mid = (low + high) / 2;
        // Find number of elements in a that are in [b - mid, b + mid]
        int left = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
        int right = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
        int count = right - left;
        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi a(N);
    rep(i, N) cin >> a[i];
    
    // Sort A for binary search
    sort(all(a));
    
    // Precompute prefix sums for faster range sum queries (not used here but shown as placeholder)
    vll prefixSums(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSums[i + 1] = prefixSums[i] + a[i];
    }

    rep(i, Q) {
        int b, k;
        cin >> b >> k;
        ll ans = solveQuery(b, k, prefixSums, a);
        cout << ans << '\n';
    }

    return 0;
}