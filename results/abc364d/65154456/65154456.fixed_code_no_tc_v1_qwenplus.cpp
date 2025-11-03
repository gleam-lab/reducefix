#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, q;
ll a[MAXN];

// Binary search on the k-th smallest distance from point b to any A_i
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the A array to enable binary search around each B_j
    sort(a, a + n);
    
    for (int j = 0; j < q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-indexed: we want the k-th smallest distance (k-1 after sorting)
        
        // We'll collect distances from b to nearby points in A
        // But instead of all points, we can use binary search to find candidates
        
        // Find the position where b would be inserted
        auto it = lower_bound(a, a + n, b);
        int pos = it - a;
        
        // Use two pointers to get the k+1 closest elements
        vector<ll> dists;
        int left = pos - 1, right = pos;
        
        // Gather up to k smallest distances
        while ((left >= 0 || right < n) && dists.size() <= k) {
            if (left >= 0 && (right >= n || abs(a[left] - b) <= abs(a[right] - b))) {
                dists.push_back(abs(a[left] - b));
                left--;
            } else if (right < n) {
                dists.push_back(abs(a[right] - b));
                right++;
            }
        }
        
        // Sort the collected distances and pick the k-th (1-indexed input)
        sort(dists.begin(), dists.end());
        cout << dists[k] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}