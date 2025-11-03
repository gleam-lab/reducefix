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
    
    // Sort the A array to enable binary search and proximity queries
    sort(a, a + N);
    
    // Process each query
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // We'll find the k-th smallest distance from B_j to any A_i
        // Instead of computing all distances, we can use binary search on answer
        // But simpler approach: find candidate positions around b
        
        // Find the position where b would be inserted
        auto it = lower_bound(a, a + N, b);
        int pos = it - a;
        
        // We consider elements around this position
        // The k-th closest must be within a window around the closest point(s)
        vector<int> candidates;
        
        // Add elements from left and right of pos
        for (int i = max(0, pos - k); i < min(N, pos + k); i++) {
            candidates.push_back(abs(a[i] - b));
        }
        
        // Sort distances to get k-th smallest
        sort(candidates.begin(), candidates.end());
        
        // Output the k-th smallest distance (1-indexed)
        cout << candidates[k-1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}