#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int a[MAXN];

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    // Read coordinates of A points
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort A points for binary search / lower_bound operations
    sort(a, a + N);
    
    // Process each query
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // Find the position where B_j would be inserted in sorted A array
        auto it = lower_bound(a, a + N, b);
        int pos = it - a;  // number of elements < b
        
        // We'll consider candidates around this position
        // We need to find the k-th smallest distance from B_j to any A_i
        
        // Instead of collecting all distances (O(N)), we can use binary search on answer
        // But simpler: since N, Q up to 1e5, O(N log N) per query is too slow
        // Alternative: collect candidate distances efficiently
        
        // Actually, we can do this: the k-th closest must be among the points near b
        // We can extract at most 2*k relevant points around position 'pos'
        
        // Define left and right bounds for candidate points
        int left = max(0, pos - k);
        int right = min(N - 1, pos + k - 1);
        
        // Extract distances from b to a[i] for i in [left, right]
        vector<int> dists;
        for (int i = left; i <= right; i++) {
            dists.push_back(abs(a[i] - b));
        }
        
        // Sort distances and pick k-th smallest
        sort(dists.begin(), dists.end());
        
        // The k-th closest (1-indexed)
        cout << dists[k-1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}