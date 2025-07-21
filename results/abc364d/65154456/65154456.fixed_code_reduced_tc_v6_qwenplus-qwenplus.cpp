#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query_kth_distance(ll b, ll k, int n) {
    vector<ll> diffs;
    for (int i = 0; i < n; ++i) {
        diffs.push_back(abs(a[i] - b));
    }
    sort(diffs.begin(), diffs.end());
    return diffs[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + N);  // Sort A once
    
    // Precompute prefix sums for binary search on sorted distances
    // We'll use binary search directly on answer instead of precomputing all possible distances
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Since we can't store all distances, we binary search on the answer
        // Distance can be between 0 and max difference (up to 2e8)
        ll low = 0, high = 2e8;
        while (low < high) {
            ll mid = (low + high) / 2;
            
            // Count how many elements in A are within distance <= mid from b
            int left = lower_bound(a, a + N, b - mid) - a;
            int right = upper_bound(a, a + N, b + mid) - a;
            int count = right - left;
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        cout << low << "\n";
    }

    return 0;
}