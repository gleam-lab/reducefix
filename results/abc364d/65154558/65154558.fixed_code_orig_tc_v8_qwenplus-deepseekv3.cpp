#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-based index

        int left = 0, right = N - 1;
        ll res = 0;

        // Binary search for the k-th smallest distance
        // We need to find the k-th smallest |A[i] - b|
        // To do this, we can use binary search on the possible distances
        // and find the smallest distance d such that there are at least k+1 elements with |A[i] - b| <= d

        ll low = 0, high = 2e14;
        while (low < high) {
            ll mid = (low + high) / 2;
            // Count the number of elements <= b + mid and >= b - mid
            auto it1 = lower_bound(A.begin(), A.end(), b - mid);
            auto it2 = upper_bound(A.begin(), A.end(), b + mid);
            int cnt = it2 - it1;
            if (cnt <= k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // Now, find the k-th smallest distance
        // Collect all elements within distance 'low' around b, then sort them by distance to b and pick the k-th
        ll d_low = low;
        vector<ll> candidates;
        auto it1 = lower_bound(A.begin(), A.end(), b - d_low);
        auto it2 = upper_bound(A.begin(), A.end(), b + d_low);
        for (auto it = it1; it != it2; ++it) {
            candidates.push_back(abs(*it - b));
        }
        sort(candidates.begin(), candidates.end());
        res = candidates[k];

        cout << res << '\n';
    }

    return 0;
}