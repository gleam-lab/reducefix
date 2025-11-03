#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int a[MAXN];

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    // Read the A points
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort A points to enable binary search and efficient distance queries
    sort(a, a + N);
    
    // Process each query
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // We'll find the k-th smallest distance from B_j to any A_i
        
        // Find the position where b would be inserted in sorted array a
        auto it = lower_bound(a, a + N, b);
        int pos = it - a;
        
        // Now we consider elements around this position
        // We'll collect candidate distances from nearby points
        // Since we need k-th closest, we only need to look at up to k elements on each side
        
        vector<int> dists;
        
        // Add distances from left side (from pos-1 down to max(0, pos-k))
        for (int i = pos - 1; i >= 0 && (pos - i) <= k; i--) {
            dists.push_back(abs(a[i] - b));
        }
        
        // Add distances from right side (from pos to min(N-1, pos+k-1))
        for (int i = pos; i < N && (i - pos + 1) <= k; i++) {
            dists.push_back(abs(a[i] - b));
        }
        
        // Sort the collected distances
        sort(dists.begin(), dists.end());
        
        // The k-th smallest distance (1-indexed)
        cout << dists[k-1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}